import tester
namaFile = 'input.csv'

def insertionSort(arr):
    for Pass in range(1,len(arr)):
        temp = arr[Pass]
        i = Pass-1
        while i >= 0 and temp[2] < arr[i][2]:
            arr[i+1] = arr[i]
            i -= 1
        arr[i+1] = temp
tester.start(namaFile)
file.open(list.csv)
insertionSort(lst)
count = 0
minusia = lst[1][2]
for line in lst:
    if int(line[3]) > 75:
        count+= 1

print(count)
print(minusia)

tester.end(namaFile)
