#include "list_circular.h"
#include <stdio.h>
void deleteAt(List *l, int idx, ElType *val){
    Address p = FIRST(*l);
    if(idx == 0) deleteFirst(l,val);
    else{
        while(--idx){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        NEXT(p) = NEXT(NEXT(p));
    }
};

int indexOf(List l, ElType val){
    int idx = 0;
    Address p = FIRST(l);
    while(p != NULL){
        if(INFO(p) == val) return idx;
        p = NEXT(p);
        idx++;
    } 
    return -1;
};

int main(){
    List l;
    CreateList(&l);
    int N, ai;
    scanf("%d", &N);

    int idx = 1;
    while(idx <= N){
        insertLast(&l,idx);
        idx++;
    }
    ElType trash;
    Address P = FIRST(l);
    while(--N){
        int len = 0;
        Address M = FIRST(l);
        while(NEXT(M) != FIRST(l)){
            len++;
            M = NEXT(M);
        }
        scanf("%d", &ai);
        if(ai < 0) ai = len - ai;
        while(ai--){
            P = NEXT(P);
        }
        deleteAt(&l, indexOf(l,INFO(P)), &trash);
    }
    printf("%d", INFO(FIRST(l)));
    return 0;
}