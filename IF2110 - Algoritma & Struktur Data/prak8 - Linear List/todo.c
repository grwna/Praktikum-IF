# include "listlinier.h"
# include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    char op;
    int val;
    while(true){
        scanf("%c", &op);
        if(op == 'X') break;
        else if(op == 'C') {
            if(!isEmpty(l)){
                deleteFirst(&l, &val);
            }
            
            
            }
        else{
            scanf("%d", &val);}
        
        if(op == 'P') insertFirst(&l, val);
        else if(op == 'I') insertLast(&l, val);
        else if(op == 'D') {
            if(indexOf(l,val) != -1){
            deleteAt(&l, indexOf(l,val), &val);
            };
        }
    }

    displayList(l);
    return 0;
}