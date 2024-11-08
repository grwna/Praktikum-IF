# import tester
# namaFile = 'output.txt'
# tester.start(namaFile)
file = input()
tabFreqVokal = [0 for _ in range(5)]
mark = '.'
i = 0
do = file[i]
text = ''
lst = ['A','a','I','i','U','u','E','e','O','o']
count = 0
while do != mark:
    if do in lst:
        count+=1
    if str.lower(do) == 'a':
        tabFreqVokal[0] += 1
    elif str.lower(do) == 'i':
        tabFreqVokal[1] += 1
    elif str.lower(do) == 'u':
        tabFreqVokal[2] += 1
    elif str.lower(do) == 'e':
        tabFreqVokal[3] += 1
    elif str.lower(do) == 'o':
        tabFreqVokal[4] += 1
    i += 1
    do = file[i-1] # bergerak
    if do != mark:
        text = text + do
hurufHolder = ''
for i in range(5):
    hurufHolder += str(tabFreqVokal[i])

tulisFile = open('output.txt','w')
tulisFile.write(hurufHolder+'\n')
tulisFile.write(str(count)+'\n')
if count >  0:
    tulisFile.write(text)
else:
    tulisFile.write('Tidak ada huruf')
tulisFile.close()
#tester.end(namaFile)