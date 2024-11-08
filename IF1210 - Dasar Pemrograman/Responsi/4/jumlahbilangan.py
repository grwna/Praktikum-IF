x = int(input())
y = int(input())
count = 0
for i in range(x,y+1):
    if i % 3 == 0 or i % 4 == 0:
        count+=1
if count == 0:
    print('Tidak Ada')
else:
    print(count)
