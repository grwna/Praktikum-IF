#include "list_circular.h"
#include <stdio.h>

List head(List *l){
    int eltrash;
    
    Address P = FIRST(*l);
    int max = INFO(P);
    while(NEXT(P) != FIRST(*l)){
        P = NEXT(P);
        if(INFO(P) > max) max = INFO(P);
    }

    while(INFO(FIRST(*l)) != max){
        deleteFirst(l, &eltrash);
        insertLast(l, eltrash);
    }
}

int main(){
    List l, minhead;
    CreateList(&l);
    CreateList(&minhead);
    boolean cwise = true, countwise = true;
    int N, el;
    scanf("%d", &N);
    int len = N;
    while ((len--))
    {
        scanf("%d", &el );
        insertLast(&l, el);
        insertLast(&minhead, el);
    }
    head(&l);
    head(&minhead);
    Address M = FIRST(minhead);

    M = NEXT(M);
    FIRST(minhead) = M;

    Address P = FIRST(l);
    while(NEXT(P) != FIRST(l)){
        int prev = INFO(P);
        P = NEXT(P);
        if((prev - INFO(P)) != 1){
            countwise = false;
        }
    }

    M = FIRST(minhead);
    while(NEXT(M) != FIRST(minhead)){
        int prev = INFO(M);
        M = NEXT(M);
        if((prev - INFO(M)) != -1){
            cwise = false;
        }
    }
    if(cwise || countwise) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}