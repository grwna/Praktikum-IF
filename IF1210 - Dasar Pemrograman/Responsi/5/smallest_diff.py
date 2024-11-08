n = int(input())
a = [0 for _ in range(n)]
a = list(map(int, input().strip().split()))

minsum = 99999
for i in range(n):
    for j in range(i+1,n):
        if abs(a[i]-a[j]) < minsum:
            minsum = abs(a[i]-a[j])
        

print(minsum)