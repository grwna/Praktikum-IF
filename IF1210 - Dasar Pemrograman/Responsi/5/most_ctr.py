N = int(input())
a = list(map(int, input().strip().split()))

nilai = [a[0]]
frek = [1]

if N == 1: 
    print(nilai[0])
    exit()
else:
    for i in range (1, N):
        same = False
        for j in range (len(nilai)):
            if a[i] == nilai[j]:
                frek[j] += 1
                same = True
                break
        if not(same):
            nilai.append(a[i])
            frek.append(1)

mostctr = max(frek)
index = []


for i in range (len(frek)):
    if frek[i] == mostctr:
        index.append(nilai[i])

print(min(index))