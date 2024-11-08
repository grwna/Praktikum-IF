#include "point.h"
#include <stdio.h>
#include <math.h>

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}
void BacaPOINT (POINT * P){
    float X,Y;
    scanf("%f %f",&X,&Y);
    CreatePoint(P,X,Y);
}
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}
boolean EQ (POINT P1, POINT P2){
    if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
        return true;
    } else {
        return false;
    }
};
boolean NEQ (POINT P1, POINT P2){
    if (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2)) {
        return true;
    } else {
        return false;
    }
}
boolean IsOrigin (POINT P){
    if (Absis(P) == 0 && Ordinat(P) == 0) {
        return true;
    } else {
        return false;
    }
}
boolean IsOnSbX (POINT P){
    if (Ordinat(P) == 0) {
        return true;
    } else {
        return false;
    } 
}
boolean IsOnSbY (POINT P){
    if (Absis(P) == 0) {
        return true;
    } else {
        return false;
    }
}
int Kuadran (POINT P){
    if (Ordinat(P) > 0 && Absis(P) > 0) return 1;
    if (Ordinat(P) > 0 && Absis(P) < 0) return 2;
    if (Ordinat(P) < 0 && Absis(P) < 0) return 3;
    if (Ordinat(P) < 0 && Absis(P) > 0) return 4;
}
POINT NextX (POINT P){
    POINT Phasil;
    Absis(Phasil) = Absis(P) + 1;
    Ordinat(Phasil) = Ordinat(P);
    return Phasil;
}
POINT NextY (POINT P){
    POINT Phasil;
    Absis(Phasil) = Absis(P);
    Ordinat(Phasil) = Ordinat(P) + 1;
    return Phasil;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT Phasil;
    Absis(Phasil) = Absis(P) + deltaX;
    Ordinat(Phasil) = Ordinat(P) + deltaY;
    return Phasil;
}
POINT MirrorOf (POINT P, boolean SbX){
    POINT Phasil;
    Absis(Phasil) = Absis(P);
    Ordinat(Phasil) = Ordinat(P);
    if (SbX) {
        Ordinat(Phasil) *= (-1);
        return Phasil;
    }
    Absis(Phasil) *= (-1);
    return Phasil;
}
float Jarak0 (POINT P){
    return sqrt((Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P)));
}
float Panjang (POINT P1, POINT P2){
    float jarakAbsis = Absis(P1) - Absis(P2);
    float jarakOrdinat = Ordinat(P1) - Ordinat(P2);
    return sqrt((jarakAbsis)*(jarakAbsis) + (jarakOrdinat)*(jarakOrdinat));
}
void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    if(SbX){
        P -> Y *= -1;
    } else {
        P -> X *= -1;
    }
}
void Putar (POINT *P, float Sudut){
    float rad = (-Sudut) * 3.14159265358979323846 / 180.0;
    float sin = sinf(rad);
    float cos = cosf(rad);
    
    
    float x = (Absis(*P) * cos) - (Ordinat(*P) * sin);
    float y = (Absis(*P) * sin) + (Ordinat(*P) * cos);

    Absis(*P) = x;
    Ordinat(*P) = y;
}
void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    float a,b;
    if (Absis(P1) == Absis(P2)){
        printf("(1,%.0f)", -round(Absis(P1)));
    } else if (Ordinat(P1) == Ordinat(P2)) {
        printf("(0,%.0f)", round(Ordinat(P1)));
    } else {
        a = (Ordinat(P2)-Ordinat(P1)) / (Absis(P2)-Absis(P1));
        b = Ordinat(P1) - (a*Absis(P1));
        printf("(%.0f,%.0f)", a,b);
    }   
}
