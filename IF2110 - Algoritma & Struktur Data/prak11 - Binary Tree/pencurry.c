#include "bintree.h"

int mencurry(BinTree T) {
    int harta1, harta2;
    if (isTreeEmpty(T)) return 0;
    else if (isOneElmt(T)) return ROOT(T);

    if (isUnerRight(T)) {
        harta1 = ROOT(T) + mencurry(LEFT(RIGHT(T))) + mencurry(RIGHT(RIGHT(T)));
        harta2 = mencurry(RIGHT(T));
    } 
    else if (isUnerLeft(T)) {
        harta1 = ROOT(T) + mencurry(LEFT(LEFT(T))) + mencurry(RIGHT(LEFT(T)));
        harta2 = mencurry(LEFT(T));
    } 
    else {
        harta1 = ROOT(T) + mencurry(LEFT(LEFT(T))) + mencurry(RIGHT(LEFT(T))) + mencurry(LEFT(RIGHT(T))) + mencurry(RIGHT(RIGHT(T)));
        harta2 = mencurry(LEFT(T)) + mencurry(RIGHT(T));
    }

    if (harta1 > harta2) return harta1; 
    else return harta2;

}