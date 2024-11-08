a=input()
b=input()

a = ord(a)
b = ord(b)
if not(65<=a<=90 and 65<=b<=90):
    print("Tidak valid")
else:
    if (a>b):
        if (a-b)>13:
            print(26-(a-b))
        else: print(a-b)
    else:
        if (b-a)>13:
            print(26-(b-a))
        else: print(b-a)
