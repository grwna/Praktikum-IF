import tester
namaFile = 'input.csv'



tester.start(namaFile)
file.open('input.csv')
holderNamaDep = []
holderGaji =[]
for line in lst:
    if line[0] == 'name':
        continue
    if line[1] not in holderNamaDep:
        holderNamaDep.append(line[1])

for i in range(len(holderNamaDep)):
    gaji = 0
    for line in lst:
        if line[1] == holderNamaDep[i]:
            gaji = gaji + int(line[2])
    holderGaji.append(gaji)

sum = 0
count = 0
for i in range(len(holderGaji)):
    print(holderGaji[i])
    sum += holderGaji[i]
    count += 1
print(round(sum/count))




    
tester.end(namaFile)
