# include "list_circular.h"
# include <stdio.h>
# include <stdlib.h>
/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
};
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
};
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address P = (Address)malloc(sizeof(ElmtList));
    if(P != NULL) {
        INFO(P) = val;
        NEXT(P) = NULL;
    }
    return P;
};
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
};
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    if(isEmpty(l)) return NULL;
    Address P = FIRST(l);
    do {
        if(INFO(P) == val) return P;
        P = NEXT(P);
    } while(P != FIRST(l));
    
    return NULL;
};
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    Address node = FIRST(l);
    do {
        if(node == p) return true;
        node = NEXT(node);
    } while(node != FIRST(l));
    return false;
};
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address P = allocate(val);
    if(isEmpty(*l)) {
        FIRST(*l) = P;
        NEXT(P) = P;
        }
    else{
        Address last = FIRST(*l);
        while(NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        NEXT(P) = FIRST(*l);
        FIRST(*l) = P;
        NEXT(last) = P;
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
void insertLast(List *l, ElType val){
    Address last = FIRST(*l);
    Address newLast = allocate(val);
    if(isEmpty(*l)) {
        FIRST(*l) = newLast;
        NEXT(newLast) = newLast;
        }
    else{
        while(NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        NEXT(last) = newLast;
        NEXT(newLast) = FIRST(*l);
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    Address P = FIRST(*l);
    *val = INFO(P);
    if(NEXT(P) == FIRST(*l)) {
        FIRST(*l) = NULL;
        deallocate(P);
    }else{
        Address last = FIRST(*l);
        while(NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        FIRST(*l) = NEXT(P);
        NEXT(last) = FIRST(*l);
        deallocate(P);
    }
};
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType * val){
    Address last = FIRST(*l);
    if(NEXT(last) == FIRST(*l)) {
        *val = INFO(last);
        FIRST(*l) = NULL;
        deallocate(last);
    }
    else {
        while(NEXT(NEXT(last)) != FIRST(*l)){
            last = NEXT(last);
        }
        Address deleted = NEXT(last);
        NEXT(last) = FIRST(*l);
        *val = INFO(deleted);
        deallocate(deleted);
    }
};
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address P = FIRST(l);
    printf("[");
    do {
        printf("%d",INFO(P));
        if(NEXT(P) != FIRST(l)) printf(",");
        P = NEXT(P);
    } while((P != FIRST(l)));
    printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
