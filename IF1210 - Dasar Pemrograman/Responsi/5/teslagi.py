def isSorted(a):
    sorted = True
    for i in range(len(a)):
        if i+1 < len(a):
            if a[i] > a[i+1]:
                sorted = False
    return sorted
a = [2,1,2,3,4,5]

if isSorted(a):
    print("Ya")
else: print('Tidak')

