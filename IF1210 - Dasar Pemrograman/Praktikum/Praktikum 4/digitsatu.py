N = int(input())
a = list(map(int, input("").split()))
cnt = 0
for i in range(N):
    angka = a[i]
    while angka > 9:
        hasil = 0
        while angka // 10 > 0:
            digit = angka % 10
            hasil = hasil + digit
            angka = angka // 10
        hasil += angka
        angka = hasil
        cnt += 1
print(cnt)  
