# include "circle.h"
# include <stdio.h>
# include <math.h>
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                  */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R) {
    return (R > 0);
};
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    Center(*C).X = X;
    Center(*C).Y = Y;
    Radius(*C) = R;
};
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C) {
    float X,Y,R;
    scanf("%f %f %f", &X,&Y,&R);
    while (!(IsCIRCLEValid(X,Y,R))) {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &X,&Y,&R);
    }
    CreateCIRCLE(C, X, Y, R);
};
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */

void WriteCIRCLE(CIRCLE C) {
    printf("P(%.2f,%.2f) r=%.2f",Absis(Center(C)),Ordinat(Center(C)),Radius(C));
};
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C) {
    return 2 * Radius(C) * 3.14;
};
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */

float Area(CIRCLE C) {
    return 3.14 * (Radius(C)*Radius(C));
};
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    return (Panjang(Center(C), P) < Radius(C));
};
/* Mengirim true jika titik P berada di dalam lingkaran C */

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {

    float tolerance = 0.0001;
    return fabs(Panjang(Center(C), P) - Radius(C)) < tolerance;
};
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float distance = Panjang(Center(C1),Center(C2));
    return (distance < fabs(C1.R - C2.R));

};
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float distance = Panjang(Center(C1), Center(C2));

    return (distance == fabs(C1.R - C2.R) || distance == C1.R + C2.R);
};
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float distanceBetweenCenters = Panjang(Center(C1), Center(C2));
    float sumRadius = C1.R + C2.R;
    float diffRadius = fabs(C1.R - C2.R);
    return (distanceBetweenCenters < sumRadius) && (distanceBetweenCenters > diffRadius);
}

/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */

/* ***************************************************************** */
