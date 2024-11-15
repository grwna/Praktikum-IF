# include "queue.h"
# include <stdio.h>

int main(){
    Queue q;
    CreateQueue(&q);
    int n, qry, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &qry);
        if(qry == 1){
            scanf("%d", &x);
            if(isFull(q)){
                printf("Queue Penuh\n");
            } else{
                enqueue(&q,x);
                printf("Enqueue %d Berhasil\n", x);
            }
        } else if(qry == 2){
            if(isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                dequeue(&q, &x);
                printf("Dequeue %d Berhasil\n", x);
            }
        } else if(qry == 3){
            if(isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", q.buffer[IDX_HEAD(q)]);
            }
        } else if(qry == 4){
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
    }
    displayQueue(q);
   return 0; 
}