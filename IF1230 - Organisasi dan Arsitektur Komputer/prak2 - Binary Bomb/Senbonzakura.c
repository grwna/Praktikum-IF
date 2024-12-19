#include <stdio.h>
#include <stdint.h>
#include <string.h>
// Ngotak atki XGCFAR
// Kalo strcspn ngambil semua, ini konstan = bdXdZh
void java_adalah_key(){
    int eax, edx, ox10, ecx; // 0x10 nyimpen indexing
    edx = ox10;
    // eax = "XGCFAR";
    eax = eax + edx; //eax = 'X'
    eax = 'R';  // <<<<<<<<<<<<+
    eax ^= 42;
    eax += 4;
    eax |= 1;
    eax ^= 37;
    ecx = eax+0x10;
    printf("%c",ecx);
    // ecx = ox10(%eax) wtf

}

// NGOTAK ATIK INPUT ASAL
// 0x224 hasil otak atik java
// 0x200 input asal 
void what_is_this(int enam, int ox224, int ox200 ){
    int eax, edx, ox10, ecx, ox11, ebx;
    ox11 = '>';
    eax = ox10;
    edx = eax + 1;  // load address
    // sign extend eax ke edx
    // idivl ox10
    // move move
    eax = ox224;
    eax += edx;
    // ambil char pertama
    eax = 'd';
    ox11 ^= (uint8_t)eax; // xor char pertama XGCFARotakatik dengan char pertama input
    printf("%c", ox11);

    // INi bakal ngulang sepanjang ox200, dan setiap nya di xor sama ox224
    // kalo ox224 < ox200 (length) ox224 tu jadi keyny dan ngulang
    // ini kayak kriptografi gitu
}

int main(){
    int hex[] = {0x0f, 0x13, 0x3d, 0x0b,
                 0x36, 0x48, 0x08, 0x05,
                 0x33, 0x0f, 0x2f, 0x48,
                 0x05, 0x0b, 0x35, 0x0d,
                 0x34, 0x00, 0x03, 0x03,
                 0x37, 0x44, 0x33, 0x1b,
                 0x11, 0x01, 0x37, 0x5b};
    int chars[] = {'b', 'd', 'X', 'd', 'Z', 'h'};
    for(int i = 0; i < 28; i++){
        printf("%c", hex[i] ^ chars[i % 6]);
    }
    return 0;
}