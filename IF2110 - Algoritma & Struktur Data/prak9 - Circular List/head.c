#include "list_circular.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    int N, el, eltrash;
    scanf("%d", &N);
    int len = N;
    while ((len--))
    {
        scanf("%d", &el );
        insertLast(&l, el);
    }
    Address P = FIRST(l);
    int max = INFO(P);
    while(NEXT(P) != FIRST(l)){
        P = NEXT(P);
        if(INFO(P) > max) max = INFO(P);
    }

    while(INFO(FIRST(l)) != max){
        deleteFirst(&l, &eltrash);
        insertLast(&l, eltrash);
    }
    displayList(l);
    return 0;
}