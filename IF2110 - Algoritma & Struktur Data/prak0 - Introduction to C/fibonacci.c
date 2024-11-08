#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int fibonacci(int n, int a, int b) {
    if (n == 1) {
        return a;
    } else if (n == 2) {
        return b;
    } else {
        return fibonacci(n-1, a, b) + fibonacci(n-2, a, b);
    }
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", fibonacci(n, a, b));
    return 0;
}
