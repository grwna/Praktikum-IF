#include <stdint.h>

void check(int param1, int param2){
    int edx = param1;   
    int eax = param2;

    int ox1c = edx;
    int ox20 = eax;
    int ecx;
    int oxc = 0;
    while(oxc <= 5){
        eax = 3*oxc;
        eax = ((0x4ec4ec4f * (eax + ox1c)) >> 32);
        eax = eax >> 3;
        eax -= (ox1c >> 31);
        eax = (ox1c - (eax * 26)) + 97;
        ox1c = eax;

        if (ox1c > 'z'){
            edx = (79 * ox1c);
            eax = eax >> 8;
            eax = eax >> 3 - edx >> 7;
            eax = edx - (26 * eax) + 97;
            ox1c = eax;
        }
        if(ox20 == ox1c){ 
            return;
        }
        oxc += 1;
    } 
    trap();
}

void Bakenohana(char* input_strings){
    int eax, par2;
    int params2[6] = {"s", "t", "e", "i", "k"}; 
    for (int i = 0; i < 6; i++){
        eax = input_strings[i];
        par2 = params2[i];
        check(eax, par2);
    }   
    return;
}