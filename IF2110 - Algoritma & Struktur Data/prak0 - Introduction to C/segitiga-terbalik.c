#include <stdio.h>
#include <stdlib.h>

int main() {
    int tinggi;
    int i, j,k,l;
    scanf("%d",&tinggi);
    for (i = 0; i < tinggi; i++) {
        for (j = 0; j <= i-1 ; j++) {
            printf(" ");
        }
        for (k = 0 ; k <= tinggi-1-i; k++) {
            printf("*");
        }
        for (l = 0 ; l <= tinggi-2-i; l++) {
            printf("*");
            }
        printf("\n");
    }
    return 0;
}