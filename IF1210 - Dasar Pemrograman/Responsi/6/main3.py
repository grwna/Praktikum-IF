import tester

tester.start("input.csv")
file = open("input.csv", "r")

def sort(arr):
   for i in range (len(arr)):
       for j in range (len(arr)):
           if (arr[j] > arr[i]):
               temp = arr[j]
               arr[j] = arr[i]
               arr[i] = temp
   return arr

data = []
for text in file:
   row = text.strip("\n")
   data.append(row.split(","))
lulus = 0
min_umur_1 = 9999
arr_umur = []
for i in range (1, len(data)):
   if (int(data[i][3]) > 75):
       lulus += 1
   arr_umur.append(data[i][2])

arr_min = sort(arr_umur)

print(lulus)
print(arr_min[1])
file.close()

tester.end("input.csv")
