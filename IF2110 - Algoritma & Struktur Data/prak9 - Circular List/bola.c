#include "list_circular.h"
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    List l;
    CreateList(&l);

    boolean del[N+69];

    for (int i = 1; i <= N; i++) {
        insertLast(&l, i);
        del[i] = false;
    }

    boolean first = 1;
    int length = N;
    for (int i = 0; i < N-1; i++) {
        int shift;
        scanf("%d", &shift);
        
        Address current = FIRST(l);
        Address prev = current;
        Address deleted = NEXT(current);
        Address next = NEXT(deleted);
        
        if (shift > 0 || first) shift--;
        shift = (shift % length + length) % length;
        
        if (shift == 0) shift = length;
        for (int j = 1; j <= shift; j++) {
            prev = NEXT(prev);
            deleted = NEXT(deleted);
            next = NEXT(next);
        }

        NEXT(prev) = next;

        FIRST(l) = deleted;
        del[INFO(deleted)] = 1;


        
        length--;
        first = false;
    }

    for (int i = 1; i <= N; i++) {
        if (!del[i]) {
            printf("%d\n", i);
            break;
        }
    }
}