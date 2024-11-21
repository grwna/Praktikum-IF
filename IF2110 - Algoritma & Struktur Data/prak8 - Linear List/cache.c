# include "listlinier.h"
# include <stdio.h>

int main(){
    int N, Q, miss = 0, hit = 0;
    ElType op, trash;
    List l;
    CreateList(&l);

    scanf("%d", &N);
    scanf("%d", &Q);

    while(Q--){
        scanf("%d", &op);
        int idx = indexOf(l, op);
        if(idx == -1 ){
            printf("miss ");
            if(length(l) == N){
                deleteLast(&l, &trash);
            }
            insertFirst(&l, op);
            miss++;
        }
        else{
            printf("hit ");
            deleteAt(&l,idx,&trash);
            insertFirst(&l, op);
            hit++;
        }
        displayList(l);
        printf("\n");
    }
    int ratio;
    if(hit + miss == 0) ratio = 0;
    else ratio = (float)hit / (hit + miss-1);
    printf("hit ratio: %.2f", ratio);
    return 0;
};