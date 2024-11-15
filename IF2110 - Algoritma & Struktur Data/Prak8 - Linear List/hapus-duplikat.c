# include "hapus-duplikat.h"
# include <stdlib.h>
void bubbleSort(List *l){
    boolean swapped;
    Address p;
    Address end = NULL; 
    do {
        swapped = false;
        p = *l;

        while (NEXT(p) != end) {
            if (INFO(p) > INFO(NEXT(p))) {

                ElType temp = INFO(p);
                INFO(p) = INFO(NEXT(p));
                INFO(NEXT(p)) = temp;
                swapped = true;
            }
            p = NEXT(p);
        }
        end = p; 
    } while (swapped);
}
List hapusDuplikat(List l){
    if(isEmpty(l)) return l; 
    List lresult, lempty;
    CreateList(&lempty);

    // Copy l into lresult
    lresult = concat(l,lempty);

    // HAPUS DUPLIKAT
    int idx = 0, currVal;  //Keep track of positions, Curr val will be checked
    Address currP = lresult, temp;
    ElType trash;
    while (currP != NULL && NEXT(currP) != NULL) {
        boolean hasDuplicate = false;
        while(NEXT(currP) != NULL && INFO(currP) == INFO(NEXT(currP))){
            temp = NEXT(currP);
            deleteAt(&lresult, idx+1, &trash);
            hasDuplicate = true;
        }

        if(hasDuplicate){
            deleteAt(&lresult, idx, &trash);
            if(lresult == NULL) return lresult;
            currP = lresult;
            idx = 0;
        }
        else {
            currP = NEXT(currP);
            idx++;
        }

    }
    bubbleSort(&lresult);
    return lresult;
};
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */