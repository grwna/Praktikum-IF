#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
   PrioQueue qa,qb;
   CreatePrioQueue(&qa);
   CreatePrioQueue(&qb);
    
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&qa,a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&qb, b);
    }

    long long ans = 0;
    int da,db;
    while(!(isEmpty(qa))){
        dequeue(&qa,&da);
        dequeue(&qb,&db);
        ans += ((long long) da) * ((long long)db);
    }
    printf("%lld\n", ans);
}