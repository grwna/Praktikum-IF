#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    int i;
    int a_i;
    int sum = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++ ) {
        scanf("%d", &a_i);
        if (a_i %k != 0) {
            sum += a_i;
        }
    }
    printf("%d\n", sum);
    return 0;
}