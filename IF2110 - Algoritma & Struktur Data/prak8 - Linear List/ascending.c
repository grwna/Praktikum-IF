# include "listlinier.h"
# include <stdio.h>

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

int main(){
    int val = 0;
    List l;
    CreateList(&l);
    while(val != -9999){
        scanf("%d", &val);
        if(val != -9999){
        insertLast(&l, val);
        }
    }
    if(!isEmpty(l)) bubbleSort(&l);
    displayList(l);
    return 0;
}