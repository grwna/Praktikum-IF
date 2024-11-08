X = int(input())
Y = int(input())
cnt = 0
for i in range(X,Y+1):
    if i % 3 == 0 or i % 4 == 0:
        cnt += 1

if cnt == 0:
    print('Tidak Ada')
else:
    print(cnt)
