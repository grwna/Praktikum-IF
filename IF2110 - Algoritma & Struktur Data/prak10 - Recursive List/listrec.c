# include "listrec.h"
# include <stdio.h>
# include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x){
    Address P = (Address) malloc(sizeof(Node));
    if(P != NULL){
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

/* Pemeriksaan Kondisi List */


boolean isEmpty(List l){
    return l == NULL;
};
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */


boolean isOneElmt(List l){
    if(isEmpty(l)) return false;
    return NEXT(l) == NULL;
};
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */


ElType head(List l){
    return INFO(l);
};
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */


List tail(List l){
    return NEXT(l);
};
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */


List konso(List l, ElType e){
    Address P = newNode(e);
    if(P != NULL){
        NEXT(P) = l;
        l = P;
    }
    return l;
};
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */


List konsb(List l, ElType e){
    Address P = newNode(e);
    if(P != NULL){
        if(isEmpty(l)){
            l = P;
        } else {
            NEXT(l) = konsb(NEXT(l), e);
        }
    }
    return l;
};
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 

List copy(List l){
    if(isEmpty(l)) return NULL;
    else{
        return konso(copy(tail(l)), head(l));
    }
};
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 


List concat(List l1, List l2){
    if(isEmpty(l1)) return l2;
    else{
        return konso(concat(tail(l1),l2),head(l1));
    }

};
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

/* Fungsi dan Prosedur Lain */
int length(List l){
    int len = 0;
    if(isEmpty(l)) return 0;
    else {
        len = 1 + length(tail(l));
    }
    return len;
};
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
boolean isMember(List l, ElType x){
    if(isEmpty(l)) return false;
    else if(head(l) == x) return true;
    else{
        return isMember(tail(l), x);
    }
};
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
void displayList(List l){
    if(isEmpty(l)) return;
    else{
        printf("%d\n", head(l));
        displayList(tail(l));
    }
};
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */