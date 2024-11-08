#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main() {
    ListDin l, resultList;
    int n ,i;
    boolean inserted = false;

    scanf("%d", &n);

    CreateListDin(&l, n);
    CreateListDin(&resultList, n+20);

    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(l, i));
        NEFF(l)++;
    }

    int left, right;
    scanf("%d", &left);
    scanf("%d", &right);

    for (i = 0; i < listLength(l); i+=2) {
        int nextstart = ELMT(l, i);
        int nextstop = ELMT(l, i+1);

        if (nextstart > right && !inserted) {
            insertLast(&resultList, left);
            insertLast(&resultList, right);
            inserted = true;
        }

        if (listLength(resultList) > 0 && ELMT(resultList, getLastIdx(resultList)) >= nextstart) {
            if (ELMT(resultList, getLastIdx(resultList)) < nextstop) ELMT(resultList, getLastIdx(resultList)) = nextstop;
            continue;
        }

        if (!inserted && nextstop >= left && right >= nextstart) {
            inserted = true;
            if (nextstart > left) nextstart = left;
            if (nextstop < right) nextstop = right;
        }

        insertLast(&resultList, nextstart);
        insertLast(&resultList, nextstop);
    }

    if (!inserted) {
        insertLast(&resultList, left);
        insertLast(&resultList, right);
    }

    for (int i = 0; i < listLength(resultList); i++) {
        if (i != listLength(resultList) - 1) printf("%d ", ELMT(resultList, i));
        else printf("%d\n", ELMT(resultList, i));
    }
}