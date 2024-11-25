#include "list_circular.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    int N, el;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &el);
        insertLast(&l, el);
    }

    int a, b, prev;
    Address P = FIRST(l);
    b = INFO(P);
    a = INFO(NEXT(P)) - INFO(P);
    prev = b;
    while(NEXT(P) != FIRST(l)){
        P = NEXT(P);
        if(INFO(P) - prev != a){
            printf("0 0");
            return 0;
        }
        prev = INFO(P);
    }

    printf("%d %d", a, b);


    return 0;
}