n = int(input())
a = [0 for _ in range (n)]
a = list(map(int, input().strip().split()))

for i in range(n):
    maxi = i  # menyimpan indeks nilai maksimum
    for j in range(i, n):
        if a[j] < a[maxi]:
            maxi = j
    a[i], a[maxi] = a[maxi], a[i]

max = 2
maxcand = a[0]
count = 0
for i in range(n):
    if maxcand != a[i] and max >= count:
         maxcand = a[i]
         count = 1
    elif maxcand == a[i]:
        count += 1
        max = count
    print(count)
    print(maxcand)
print()
print(maxcand)