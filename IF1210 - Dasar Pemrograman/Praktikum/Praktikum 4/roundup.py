N = int(input())
if N <= 0 or N > 100:
    print('Tidak valid')
else:
    a = list(map(int, input("").split()))
    
    X = int(input())
    temp = []
    for i in range(N):
        for j in range(N-i-1):
            if a[j] > a[j+1]:
                a[j+1],a[j] = a[j],a[j+1]
      
    for i in range(N):
        if a[i] > X:
            temp.append(a[i])
    if len(temp) < 2:
        print(-1)
    else:
        print(temp[1])