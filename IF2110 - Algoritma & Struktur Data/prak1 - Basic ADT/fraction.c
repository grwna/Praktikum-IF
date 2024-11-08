#include "fraction.h"
#include <stdio.h>
#include <math.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

boolean IsFRACTIONValid(int N, int D) {
    return D != 0;
};
/* Mengirim TRUE jika pecahan valid */

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R) {
    Numerator(*F) = N;
    Denominator(*F) = R;
};
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F) {
    int N,R;
    scanf("%d %d", &N,&R);
    while (!(IsFRACTIONValid(N,R))) {
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &N,&R);
    }
    CreateFRACTION(F,N,R);
};
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */

void WriteFRACTION(FRACTION F) {
    F = SimplifyFRACTION(F);
    printf("%d/%d",F.N,F.D);
};
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION Fhasil;
    int commonDenom = F1.D * F2.D;
    int newNum1 = F1.N * F2.D;
    int newNum2 = F2.N * F1.D;
    
    Fhasil.N = newNum1 + newNum2;
    Fhasil.D = commonDenom;

    return SimplifyFRACTION(Fhasil);
};
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION Fhasil;
    int commonDenom = F1.D * F2.D;
    int newNum1 = F1.N * F2.D;
    int newNum2 = F2.N * F1.D;

    Fhasil.N = newNum1 - newNum2;
    Fhasil.D = commonDenom;
    
    return SimplifyFRACTION(Fhasil);
};
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION Fhasil;
    Fhasil.N = F1.N * F2.N;
    Fhasil.D = F1.D * F2.D;
    
    return SimplifyFRACTION(Fhasil);
};
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION Fhasil;
    Fhasil.N = F1.N * F2.D;
    Fhasil.D = F1.D * F2.N;
    int gcdd = gcd(Fhasil.N,Fhasil.D);
    Fhasil.N /= gcdd;
    Fhasil.D /= gcdd;
    return Fhasil;
};
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    FRACTION Fhasil;
    Fhasil.N = F1.N * n;
    Fhasil.D = F1.D;
    return SimplifyFRACTION(Fhasil);
};
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F) {
    FRACTION Fhasil ;
    int gcdd = gcd(F.N,F.D);
    Fhasil.N = F.N / gcdd;
    Fhasil.D = F.D / gcdd;
    if (Fhasil.D < 0) {
        Fhasil.D *= -1;
        Fhasil.N *= -1;
    }
    return Fhasil;
};
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */

float ToDecimal(FRACTION F) {
    return (float)F.N/(float)F.D;
};
/* Mengonversi FRACTION ke bentuk desimal */
