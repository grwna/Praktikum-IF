#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    if (a <= b) {
        printf("%d",a);
        }
    while (a <= b) {
        if (a %2 == 0) {
            a *= 2;
        } else {
            a++;
        }
        if (a > b) {
            break;
        } else{
            printf(" %d",a);
        }
        
    }
    printf("\n");
    
    return 0;
}