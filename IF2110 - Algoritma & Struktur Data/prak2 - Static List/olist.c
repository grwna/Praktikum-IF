# include "liststatik.h"
# include <stdio.h>

int main() {
    ListStatik l,result;
    int i,j,count;
    boolean duplicate;
    readList(&l);
    CreateListStatik(&result);

    // Creating result list without duplicates
    result = createSet(l);
    printList(result);
    printf("\n");

    for (i = 0; i < listLength(result); i++){
        printf("%d %d\n", result.contents[i], countVal(l, result.contents[i]));
    }
    return 0;
}