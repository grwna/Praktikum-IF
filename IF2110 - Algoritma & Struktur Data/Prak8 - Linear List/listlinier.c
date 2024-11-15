# include "listlinier.h"
# include <stdio.h>
# include <stdlib.h>

Address newNode(ElType val){
    Address p;
    p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
};

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
};
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
};
/* Mengirim true jika list kosong */


/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int i;
    Address p = l;
    for (i = 0; i < idx; i++){
        p = NEXT(p);
    }
    return INFO(p);
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int i;
    Address p = *l;
    for (i = 0; i < idx; i++){
        p = NEXT(p);
    }
    INFO(p) = val;
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    int idx = 0;
    Address p = l;
    while(p != NULL){
        if(INFO(p) == val) return idx;
        p = NEXT(p);
        idx++;
    } 
    return IDX_UNDEF;
};
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address new = newNode(val);
    if(new != NULL){
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
    
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p = *l;
    Address new = newNode(val);
    if(new != NULL){
        if (p == NULL){
            *l = new;
        }
        else {
            while(NEXT(p) != NULL){
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    Address new = newNode(val);
    Address p = *l;
    if(new != NULL){
        if(idx == 0){
            NEXT(new) = *l; // Point ke awal list
            *l = new;   // Awal list diubah jadi new
        }
        else {
            while(--idx){       // TANDAI BERAT YA
                p = NEXT(p);
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
    
};
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    *val = INFO(*l);
    if(NEXT(*l) == NULL){
        *l = NULL;
    }
    else {
        *l = NEXT(*l);  // El awal berubah jadi el yang ada berikutnya
    }
};
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p = *l;
    int i;
    if(NEXT(p) == NULL){
        *val = INFO(p);
        *l = NULL;
    }
    else {
        while(NEXT(NEXT(p))!= NULL){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        NEXT(p) = NULL;
    }

};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    Address p = *l;
    if(idx == 0) deleteFirst(l,val);
    else{
        while(--idx){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        NEXT(p) = NEXT(NEXT(p));
    }
};
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p = l;
    printf("[");
        while(p != NULL){
            printf("%d", INFO(p));
            p = NEXT(p);
            if(p != NULL) printf(",");
        }
        
    printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    Address p = l;
    int len = 0;
    while( p != NULL){
        p = NEXT(p);
        len++;
    } 
    return len;
};
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address p1 = l1, p2 = l2;
    int val;
    while(p1 != NULL){
        val = INFO(p1);
        insertLast(&l3,val);
        p1 = NEXT(p1);
    }
    while(p2 != NULL){
        val = INFO(p2);
        insertLast(&l3,val);
        p2 = NEXT(p2);
    }
    return l3;
};
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
