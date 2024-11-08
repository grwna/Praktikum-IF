def prima(n):
    a = []
    x = 1
    loopCnt = 0
    while loopCnt < n:
        while True:
            x += 1
            prime = True
            y = 2
            while y <= x:
                if  x % y == 0 and y!= x:
                    prime = False
                y+=1
            if prime: break  
        if prime and y != x:
            a.append(x)
            loopCnt += 1
    return a

def rotasiKanan(a,b,x):
    newA = []
    for i in range(len(a)):
        if i != len(a)-1:
            newA.append(a[i])
    if x < len(a):
        newA = [b[x]] + newA
    return newA



n = int(input())
x = 1
if n < 1: print('Tidak valid')
else:
    a = prima(n)
    b = prima(n)
    for i in range(n):
        for j in range(n):
            if j == n-1:
                print(a[j],end='')
            else:
                print(a[j],end=' ')
        print()
        a = rotasiKanan(a,b,x)
        x+=1

