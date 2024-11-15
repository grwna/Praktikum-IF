# include "prioqueue.h"
# include <stdio.h>
/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
};
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq){
    return IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF; 

};
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFull(PrioQueue pq){
    return (IDX_TAIL(pq) + 1) % CAPACITY == IDX_HEAD(pq);

};
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(PrioQueue pq){
    if(isEmpty(pq)) return 0;
        else if(isFull(pq)) return CAPACITY;
        else return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1 + CAPACITY) % CAPACITY;
};
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val) {
    if (isFull(*pq)) {
        return; // Queue is full, cannot insert
    }

    // Step 1: If the queue is empty, initialize head and tail
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
        return;
    }

    // Step 2: Insert new element at the next tail position
    IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
    TAIL(*pq) = val;

    // Step 3: Find the correct position to insert the element
    int idx = IDX_TAIL(*pq);
    int idxPos = IDX_TAIL(*pq);

    // Find the insertion point
    while (idx != IDX_HEAD(*pq)) {
        int prevIdx = (idx - 1 + CAPACITY) % CAPACITY;
        if (pq->buffer[prevIdx] >= val) {
            break;
        }
        pq->buffer[idx] = pq->buffer[prevIdx];
        idx = prevIdx;
    }

    // Insert the element at the correct position
    pq->buffer[idx] = val;
}

/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */

void dequeue(PrioQueue *pq, ElType *val){
    *val = HEAD(*pq);
        if(length(*pq) == 1){
                IDX_HEAD(*pq) = IDX_UNDEF;
                IDX_TAIL(*pq) = IDX_UNDEF;
        } else IDX_HEAD(*pq) = (IDX_HEAD(*pq) +1) % CAPACITY; 
};
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq){
    int idx = IDX_HEAD(pq);
        int len = length(pq);
        printf("[");
        while(len > 0){
                len--;
                printf("%d", pq.buffer[idx]);
                if(len > 0) printf(",");
                idx = (idx + 1) % CAPACITY;
        }
        printf("]\n");
};
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */


