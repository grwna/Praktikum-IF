import tester
namaFile= 'input.txt'
tester.start(namaFile)

file = open('input.txt','r')
layer = file.readline()
if int(layer) <= 0:
    print('Jumlah layer:' + '0') 
else:
    print('Jumlah layer: '+ layer)
    for i in range(int(layer)):
        print('Layer ke-' + str(i+1))

        aktivasi = file.readline()
        neuron = file.readline()
        weight = file.readline()
        bias = file.readline()
        weightList = []
        biasList = []

        mark = ' '
        holderTeks = ''
        for char in weight:
            if char != 'mark' and char != '\n':
                holderTeks += char 
            if char == 'mark':
                weightList.append(holderTeks) 
                holderTeks = ''
        

        print('Fungsi aktivasi: ',end='')
        print(aktivasi,end='')
        print('Jumlah neuron: ',end='')
        print(int(neuron),end='')
        print('Weight neuron: ',end='')
        print(weightList)
        print('Bias: ',end='')
        print(bias)
        print()
file.close()
tester.end(namaFile)