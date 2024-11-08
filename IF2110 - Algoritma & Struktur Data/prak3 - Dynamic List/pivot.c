# include "listdin.h"
# include <stdio.h>

int main(){
    ListDin l, left,right;

    int n, i;
    scanf("%d", &n);

    CreateListDin(&l,n);
    CreateListDin(&left,n);
    CreateListDin(&right,n);

    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(l,i));
    }

    ELMT(left, 0) = ELMT(l, 0);
    ELMT(right, n-1) = ELMT(l, n-1);
    NEFF(left)++;
    NEFF(right)++;
    
    for (i = 1; i < n; i++) {
        if (ELMT(l, i) > ELMT(left, i-1)) {
            ELMT(left, i) = ELMT(l, i);
        }
        else {
            ELMT(left, i) = ELMT(left, i-1);
        }

        if (ELMT(l, n-i-1) < ELMT(right, n-i)) {
            ELMT(right, n-i-1) = ELMT(l, n-i-1);
        }
        else {
            ELMT(right, n-i-1) = ELMT(right, n-i);
        }
        
        NEFF(left)++;
        NEFF(right)++;
    }

    int result = 0;
    for (i = 0; i < n; i++){
        int less = -999;
        int great = 99999999999999999999;

        if (i > 0) {less = ELMT(left, i-1);}
        if (i < n-1) { great = ELMT(right, i+1);}
        if (great > ELMT(l,i) && less < ELMT(l,i)) result++;
    }

    printf("%d\n", result);

    return 0;
}