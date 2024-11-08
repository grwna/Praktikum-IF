import tester
tester.start("output.txt")
kalimat = input()
ctr_a, ctr_i, ctr_u, ctr_e, ctr_o = 0, 0, 0, 0, 0
count = 0
text = ""
for huruf in kalimat:
   if (huruf == "."):
       break
   text += huruf
   if huruf in "Aa":
       ctr_a += 1
   if huruf in "Ii":
       ctr_i += 1
   if huruf in "Uu":
       ctr_u += 1
   if huruf in "Ee":
       ctr_e += 1
   if huruf in "Oo":
       ctr_o += 1
count = ctr_a + ctr_i + ctr_u + ctr_e + ctr_o

if (count == 0): text = "Tidak ada huruf"

file = open("output.txt", "w")
file.write(str(ctr_a))
file.write(str(ctr_i))
file.write(str(ctr_u))
file.write(str(ctr_e))
file.write(str(ctr_o))
file.write("\n")
file.write(str(count))
file.write("\n")
file.write(text)
file.close()

tester.end("output.txt")
