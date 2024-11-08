a = [0 for i in range(0)]
while True:
    n = int(input())
    if n == -9999:
        break
    a.append(n)

for k in range(1,9999):
    valid = True
    for i in range(len(a)):
        for j in range(i+1,len(a)):
            if k not in a:
                if a[i] + a[j] == k:
                    valid = False
    if valid and k not in a:
        out = k
        break
print(out)
