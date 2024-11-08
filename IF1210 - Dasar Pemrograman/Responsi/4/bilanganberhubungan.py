n = abs(int(input()))
x = int(input())
a = [0 for i in range(n)]
a = list(map(int, input("").split()))

found = False
foundID = a[0]
maxd = abs(a[0]-x)
minID = a[0]
mind = abs(a[0]-x)
maxID = a[0]

for i in range(n):
    if a[i] == x:
        found = True
        foundID = a[i]
    if abs(a[i]-x) < mind and a[i] != x:
        mind = abs(a[i]-x)
        minID = a[i]
    if abs(a[i]-x) > maxd and a[i] != x:
        maxd = abs(a[i]-x)
        maxID = a[i]


if found:
    print(foundID)
    print(minID)
    print(maxID)
else:
    print('TIDAK ADA')
    print(minID)
    print(maxID)