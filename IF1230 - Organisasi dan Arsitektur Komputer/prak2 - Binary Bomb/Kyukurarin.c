#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void f(int ox420){
    int edx, eax, ox218, ox210, ecx;
    ox218 = 8;
    // jika oxc = "push eax"
     eax = ox420;
    ox210 = 1;
    for (ox218 = 0; ox218 < 20; ox218++){ //loop sampai null term (0)
        // for each letter in "push eax"
    }
    eax = ox218;// length dari ox2c "push eax"
    edx = eax + 1;
    // movb, +134, nambah 0x20 (whitespace) ke belakang push eax
    
    // <+146> di bagian ini yang dicek
    //EDI "sub eax, ebx" atau ox200, prosesny sama seperti atas
    ecx = edx + 1; // length "push eax " + 1
    //loop
    eax = edx + ox218; // jadinya 9 + 12
    // hasil "push eax sub eax, ebx"
    // setelah beberapa proses : " eax, sub eax, ebx"

}

void c(){
    int oxd, edx, eax, edi;
    oxd = 1;
    // edx = ox1fc  wtf is this = 0
    // esi = "push eax sub..." yada ydad hasil f
    edi = edx;
    // lods, scads, jne. Load string esi, terus bandingin
    // kalo sama dengan 0 loop berenti
    // sama aj kayak yang di f cok
    oxd = 0; /* jump */ oxd = 1;
    
}

void Kyukurarin(){
    int  ecx;
    uint64_t eax, edx;
    char *ox41c = "10"; // Input
    FILE *ox410 = fmemopen(ox41c, 64, "r");

    int ox414;  // Ini apaan cok mov edi
    fscanf(ox410, "%d", &ox414);
    int ox40c = ox414 ^ 12;  // 9

    ecx = ox414 * 69; // 0x159 345
    edx = 0x6bca1af3; //1808407283

    // GAMBAR 2
    eax = ecx * edx;
    eax >>= 32;
    eax >>= 3;
    edx = ecx >> 31;
    eax -= edx;

    int ox408 = eax; //12
    edx = ox408;
    eax <<= 3;
    eax = 3*edx + 2*eax; //156
    edx = ecx - eax; //3
    ox408 = edx; //3
    // mov 0x193dx(%ebx), %eax // <f> push %ebp
    // EAX menjadi address dari function

    // lea -0x404(%ebp), %esi
    int esi = 9;    // ??
    int ox424 = esi;

    edx = ox408;
    char* a = "mov eax, ebx"; //eax = 0x407c80
    edx *= 500; // ini untuk adjust eax ke next, terus esp -= 500
    // eax += edx;  eax = 0x408225c -> "sub eax, ebx"
    // mov esp, edx
    edx = 0;
    // esi = "sub eax, ebx"
    ecx = 0x7d;
    // rep movsl, overwrite memori dll
    // EDX = "sub eax, ebx"
    // ESI = "xor eax, ebx"
    edx = ox40c*500;    // add edx, eax "push eax"
    // mov esp edx, edx = *** "C", esi = "push eax"
    // eax = 0x7d
    // rep movsl, overwrite memori dll %dx:%esi, %es:%edi
    f(0x424); // 9

    fgetc(ox410);
    char ox210[5000];
    fgets(ox210, 5000, ox410);
    // printf("EAX: 0x%llx\n", eax);
    printf("EDX: %llx\n", ox40c);
    eax = 0; // gatau
    eax = strcspn("","\n");
    ox210[eax] = 0;
    // eax = esp;
    // edi = eax;
    // kemudian rep movsl dengan setup2 sebelumnya
    // terus di akhir dapat keluaran f (push eax sub eax, ebx)
    // di eax, terus pindahin ke edi
    // terus rep movsl, lagi, tidak ad perubahan di eax
    
    eax = 1; //sete
    ecx = ox414;
}

int experiment(){
    int i = 111;
    int ox40c = i ^ 12;  // 9
    int64_t ecx, edx, eax;
    ecx = i * 69; // 0x159 345
    edx = 0x6bca1af3; //1808407283

    // GAMBAR 2
    eax = ecx * edx;
    eax >>= 32;
    eax >>= 3;
    edx = ecx >> 31;
    eax -= edx;

    int ox408 = eax; //12
    edx = ox408;
    eax <<= 3;
    eax = 3*edx + 2*eax; //156
    edx = ecx - eax; //3
    printf("1: %d\n2: %d", ox40c, edx);
}

int experiment2(){
    int ox40c = 20;  // 9
    int64_t ecx, edx, eax;
    for (int i = -100; i < 1000; i++){
        if((i ^ 12) <= -1){
            ecx = i * 69; // 0x159 345
            edx = 0x6bca1af3; //1808407283

            // GAMBAR 2
            eax = ecx * edx;
            eax >>= 32;
            eax >>= 3;
            edx = ecx >> 31;
            eax -= edx;

            int ox408 = eax; //12
            edx = ox408;
            eax <<= 3;
            eax = 3*edx + 2*eax; //156
            edx = ecx - eax; //3
            if(edx <= -1){
                printf("XOR :%d\n", i ^ 12);
                printf("EDX :%d\n", edx);
                printf("%d\n", i);
            }
        }
       
    }
    
}

int main(){
    experiment();
    return 0;
}

//0x408650