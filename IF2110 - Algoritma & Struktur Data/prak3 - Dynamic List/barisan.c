# include "listdin.h"
# include <stdlib.h>
# include <stdio.h>

int main(){
    ListDin l;
    CreateListDin(&l,1000);
    readList(&l);
    int i,j, bkstep;
    bkstep = 0;
    int temp;
    for (int i = 0; i < listLength(l) - 1; i++) {
        for (int j = i + 1; j < listLength(l); j++) {
            if ((l.buffer[i] > l.buffer[j])) {
                temp = l.buffer[i];
                l.buffer[i] = l.buffer[j];
                l.buffer[j] = temp;
                bkstep++;
            }
        }
        
    }
    printf("%d\n", bkstep);
    return 0;
}