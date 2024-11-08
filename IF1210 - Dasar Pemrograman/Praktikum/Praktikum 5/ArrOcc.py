N = int(input())
A = [0 for i in range(N)]
A = list(map(int, input().strip().split()))

# Sorting
for i in range(N):
    maxi = i  # simpan indeks maksimum
    for j in range(i, N):
        if A[j] < A[maxi]:
            maxi = j
    A[i], A[maxi] = A[maxi], A[i]

index = [0 for i in range(1000)]
for i in range(N):
    for j in range(1000):
        if A[i] == j:
            index[j] += 1

max = -999999
for j in range(1000):
        if index[j] > max:
             max = j
print(max)