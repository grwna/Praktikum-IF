# include "mesinkata.h"
# include <stdio.h>

int main(){
    char charHolder;
    int evenOdd = 1;
    int index;
    STARTWORD();
    while(!EndWord){
        if (evenOdd % 2 == 1){
            index = currentWord.Length-1;
            for(int i = 0; i < (currentWord.Length / 2); i++){
                charHolder = currentWord.TabWord[i];
                currentWord.TabWord[i] = currentWord.TabWord[index];
                currentWord.TabWord[index] = charHolder;
                index--;
            }
        }
        for(int i = 0; i < currentWord.Length; i++){
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        if(!EndWord){
            printf(" ");
        }
        evenOdd++;
    }
    printf("\n");
    return 0;
}