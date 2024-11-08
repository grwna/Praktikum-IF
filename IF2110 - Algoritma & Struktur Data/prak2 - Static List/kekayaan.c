# include "liststatik.h"
# include <stdio.h>

int main(){
    ListStatik l;
    int i, lastIdx;
    readList(&l);
    lastIdx = getLastIdx(l);

    l.contents[lastIdx] += 1;
    for (i = lastIdx; i >= 0; i--){
        if (l.contents[i] == 10 && i != 0) {
            l.contents[i] = 0;
            l.contents[i-1] +=1;
        }
    }
    if (l.contents[0] == 10) {
        l.contents[0] = 0;
        insertFirst(&l,1);
        }
    lastIdx = getLastIdx(l);
    for (i = 0; i <= lastIdx; i++){
        printf("%d", l.contents[i]);
        if (i < lastIdx){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}