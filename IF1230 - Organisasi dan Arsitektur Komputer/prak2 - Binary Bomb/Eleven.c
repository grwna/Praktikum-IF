#include <stdio.h>

void feel_like_eleven(int* input, int* eax ){
    int x = sscanf(input, "%d %d %d %d %d %d");
    if(x > 6){
        return;
    } else {
        trap();
    }
}

void Eleven(int* input){
    int eax, edx;
    feel_like_eleven(input, &eax);

    // int ox2c = 1;
    if (eax != 1) {
        trap();
    }

    for (int ox2c = 1; ox2c <= 7; ox2c++){
        eax = ox2c - 1;
        edx = input[eax];
        if(ox2c <= 4){
            if(edx != ox2c*ox2c*ox2c){
                trap();
            }
        }
        else{
            if(edx != ox2c * 2 + 1){
                trap();
            }
        }
    }
    stage_complete();
}

