#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    Address holder;
    if(isTreeEmpty(*p)) return;
    else if(isOneElmt(*p)) return;

    if(isUnerLeft(*p)){
        invertTree(&LEFT(*p));
        RIGHT(*p) = LEFT(*p);
        LEFT(*p) = NULL;
    }
    else if(isUnerRight(*p)){
        invertTree(&RIGHT(*p));
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = NULL;
    }
    else {
        invertTree(&LEFT(*p));
        invertTree(&RIGHT(*p));
        holder = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = holder;
    }
    
}