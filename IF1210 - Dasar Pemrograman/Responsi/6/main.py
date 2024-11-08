import tester

tester.start("input.txt")
file = open("input.txt", "r")

depth = int(file.readline())
if depth < 0: depth = 0
print("Jumlah layer:", depth)

for i in range(depth):
    print()
    act = file.readline().strip()
    n = int(file.readline())
    weight = []
    for j in range(n):
        weight += file.readline().strip("\n").split(" ")
    bias = file.readline().strip("\n").split(" ")
    print("Layer ke-" + str(i+1))
    print("Fungsi aktivasi:", act)
    print("Jumlah neuron:", n)
    print("Weight neuron:", weight)
    print("Bias:", bias)

file.close()
tester.end("input.txt")
