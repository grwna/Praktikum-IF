N = int(input())
if N <= 0 or N%2 == 0:
    print('Masukan tidak valid')
else:
    for i in range(1,N+1):
        if i <= N/2:
            print(' ' * int(N/2 - i + 1) + '*' * (2*i-1))
        else:
            print(' ' * int(i - N/2) + '*' * (2*(N-i)+1))