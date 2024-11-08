N = int(input())
M = int(input())

a = [M]
for i in range(N):
    for j in range(i+1):
        if i == j:
            print(a[j],end='')
        else:
            print(a[j],end=' ')
    a2=[] 
    a2.append(a[0]) 
    for i in range(len(a)-1): 
        a2.append(a[i]+a[i+1]) 
    a2.append(a[-1]) 
    a=a2 

    print()