# include "matrix.h"
# include <stdio.h>

int main(){
    Matrix M;
    readMatrix(&M, 8,8);
    boolean hitam; // true jika hitam
    int bidakHitam, bidakPutih = 0;
    bidakHitam = bidakPutih = 0;
    int i,j;
    for(i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if((i + j) % 2 == 0 ) hitam = true;
            else hitam = false;

            if (hitam && ELMT(M,i,j)) bidakHitam++;
            else if (!hitam && ELMT(M,i,j)) bidakPutih++;
        }
    }
    printf("%d %d", bidakHitam,bidakPutih);
    return 0;
}