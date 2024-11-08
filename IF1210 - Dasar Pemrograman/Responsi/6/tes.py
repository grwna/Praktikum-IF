txt = "hello, my name is Peter, I am 26 years old"

x = txt.split(",")
for i in range(len(x)):
    x[i] = x[i].strip()
print(x)