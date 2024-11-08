#include "rotating_point.h"
#include <stdio.h>

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX Chasil = C;
    int i;
    for (i = 0; i < p; i++) {
        C = MultiplyCOMPLEX(C,Chasil);
    }
    return Chasil;
};

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    COMPLEX pC = C;
    int i;
    float x,y;

    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }

    for (i=1; i<=n; i++) {
        x = Absis(*P);
        y = Ordinat(*P);
        Absis(*P)= x * Real(C) - y*Imag(C);
        Ordinat(*P) = x * Imag(C) + y*Real(C);
        C = MultiplyCOMPLEX(C,pC);
        if (Jarak0(*P) >= 1) {
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi",n);
    }
    

