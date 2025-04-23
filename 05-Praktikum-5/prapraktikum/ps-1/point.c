#ifndef POINT_H
#define POINT_H

#include "boolean.h"  
#include <math.h>

/* Definisi type POINT */
typedef struct {
    float X;  /* absis (sumbu X) */
    float Y;  /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P)   (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P) {
    scanf("%f %f", &Absis(*P), &Ordinat(*P));
}

/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P) {
    printf("(%f,%f)", Absis(P), Ordinat(P));
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P) {
    return Absis(P);
}

float GetY(const POINT P) {
    return Ordinat(P);
}

void SetX(POINT *P, float X) {
    Absis(*P) = X;
}

void SetY(POINT *P, float Y) {
    Ordinat(*P) = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P) { /* true jika P = (0,0) */
    if (Absis(P) == 0 && Ordinat(P) == 0) {
        return true;
    } else {
        return false;
    }
}  

boolean IsOnSbX(POINT P) {      /* true jika Y = 0 */
    if (Ordinat(P) == 0) {
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbY(POINT P) {      /* true jika X = 0 */
    if (Absis(P) == 0) {
        return true;
    } else {
        return false;
    }
}

int Kuadran(POINT P) { /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */
    if (IsOrigin(P) || IsOnSbX(P) || IsOnSbY(P) == false) {
        if (Absis(P) > 0 && Ordinat(P) > 0) {
            return 1;
        } else if (Absis(P) < 0 && Ordinat(P) > 0) {
            return 2; 
        } else if (Absis(P) < 0 && Ordinat(P) < 0) {
            return 3;
        } else if (Absis(P) > 0 && Ordinat(P) < 0) {
            return 4;
        }
    }
}      

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2) {  /* true jika X dan Y identik */
    if (Absis(P1) == (Absis(P2)) && Ordinat(P1) == (Ordinat(P2))) {
        return true;
    } else {
        return false;
    }
}

boolean NonEquals(POINT P1, POINT P2) {/* negasi Equals */
    if (Equals(P1, P2) == true) {
        return false;
    } else {
        return true;
    }
}

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float Distance(POINT P1, POINT P2) {
    return (sqrt((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2))));
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT MidPoint(POINT P1, POINT P2) {
    POINT MidPoint;
    Absis(MidPoint) = (Absis(P1) + Absis(P2)) / 2.0;
    Ordinat(MidPoint) = (Ordinat(P1) + Ordinat(P2)) / 2.0;
    return MidPoint;
}

#endif  /* POINT_H */