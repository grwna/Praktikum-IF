# include "mesinkata.h"
# include <stdio.h>

int main(){
    int shift;
    scanf("%d", &shift);
    shift %= 26;
    START();
    IgnoreBlanks();
    while(!EOP){
        if (currentChar >= 97 && currentChar <= 122){
            currentChar -= shift;
            if(currentChar < 97) currentChar += 26;
        } else if(currentChar >= 65 && currentChar <= 90){
            currentChar -= shift;
            if(currentChar <  65) currentChar += 26;
        }
        printf("%c", currentChar);
        ADV();
    }
    printf("\n");
    return 0;
}