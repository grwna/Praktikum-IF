# include "listlinier.h"
# include <stdio.h>

List reverseList(List l){
    int len = length(l);
    List result;
    CreateList(&result);
    Address(p) = l;
    while (len--){
        insertFirst(&result, INFO(p));
        p = NEXT(p);
    }
    return result;
}

int main(){
    int val = 0;
    List l1,l2, lresult;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&lresult);
    while(true){
        scanf("%d", &val);
        if(val == -1) break;
        insertLast(&l1, val);
    }
    while(true){
        scanf("%d", &val);
        if(val == -1) break;
        insertLast(&l2, val);
    }
    

    int len1 = length(l1);
    int len2 = length(l2);
    int lenzero = len1 > len2 ? len1 - len2 : len2 - len1;
    int len = len1 > len2 ? len1 : len2;
    
    while(lenzero--){
        if(len1 > len2)insertFirst(&l2,0);
        else insertFirst(&l1,0);
    }

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Address p1 = l1;
    Address p2 = l2;
    int carry, sum;
    boolean tambahlagi;
    carry = 0;
    while(len--){
        sum = 0;
        sum = INFO(p1) + INFO(p2) + carry;
        if(len == 0 && sum > 9) tambahlagi = true;
        if(sum > 9){
            sum = sum - 10;
            carry = 1;
        } else (carry = 0);
        insertFirst(&lresult, sum);
        p1 = NEXT(p1);
        p2 = NEXT(p2);
        
    }
    if(tambahlagi) insertFirst(&lresult, 1);
    Address p = lresult;
    while(p != NULL){
        printf("%d", INFO(p));
        p = NEXT(p);
        if(p != NULL) printf(" ");
    }
    printf("\n");
        
}
