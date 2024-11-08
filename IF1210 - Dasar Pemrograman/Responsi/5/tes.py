def isSorted(a):
    sorted = True
    for i in range(len(a)):
        if i+1 <= len(a):
            if a[i] > a[i+1]:
                sorted = False
    return sorted
def rotasiArray(a):
    hldr = a[len(a)]
    a = a[:len(a)-1]
    a = [hldr] + a 
    return a

n =int(input())
a = list(map(int, input().strip().split()))

