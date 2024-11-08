def isSorted(a):
    sorted = True
    for i in range(len(a)):
        if i+1 < len(a):
            if a[i] > a[i+1]:
                sorted = False
    return sorted

N = int(input())
A = list(map(int, input().strip().split()))
B = A.copy()
cnt = 0

if isSorted(A):
    print(0)
else:
    for i in range(N):
        maxi = i 
        for j in range(i, N):
            if B[j] < B[maxi]:
                maxi = j
        B[i], B[maxi] = B[maxi], B[i]

    while True:
        AN = A[N-1]
        for i in range(N-1,0,-1):
            A[i] = A[i-1] 
        A[0] = AN
        if A == B:
            break
        else:
            cnt += 1
        if cnt > N*2:
            break
    if cnt+1 >= N:
        print("Tidak")
    else:
        print(cnt+1)


    
