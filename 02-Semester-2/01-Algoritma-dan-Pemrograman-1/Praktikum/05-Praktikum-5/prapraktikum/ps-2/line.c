/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>
#include <math.h>

// NILAI HANYA 71.5
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk LINE *** */
void CreateLine (LINE * L, POINT P1, POINT P2) {
   PAwal(*L) = P1;
   PAkhir(*L) = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaLINE (LINE * L) {
   POINT P1;
   POINT P2;
   do {
      BacaPOINT(&P1);
      BacaPOINT(&P2);
      
      if (EQ(PAwal(*L), PAkhir(*L)) == true) {
         printf("Invalid Line\n");
      }
   } while (EQ(PAwal(*L), PAkhir(*L)) == true);
   CreateLine(L, P1, P2);
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai LINE yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk LINE yang valid 
   LINE disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan line tidak valid, diberikan pesan kesalahan: 
   "Invalid Line" */
/* Contoh:
   2 3
   2 3
   Invalid Line
   2 3
   3 3 
   --> terbentuk line L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

void TulisLINE (LINE L) {
   printf("(");
   TulisPOINT(PAwal(L));
   printf(",");
   TulisPOINT(PAkhir(L));
   printf(")");
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

/* *** Kelompok operasi line *** */
float PanjangLINE (LINE L) {
   float distance_absis = Absis(PAkhir(L)) - Absis(PAwal(L));
   float distance_ordinat = Ordinat(PAkhir(L)) - Ordinat(PAwal(L));
   float distance = sqrt(distance_absis * distance_absis + distance_ordinat * distance_ordinat);
   return distance;
}

/* Menghitung panjang line L : berikan rumusnya */
float Gradien (LINE L) {
   if (Absis(PAkhir(L)) - Absis(PAwal(L)) == 0) {
      return;
   } else {
      float diff_x = Absis(PAkhir(L)) - Absis(PAwal(L));
      float diff_y = Ordinat(PAkhir(L)) - Ordinat(PAwal(L));
      float gradien = diff_y/diff_x;
      return gradien;
   }
}
/* Mengembalikan Gradien (m) dari L */
/* Gradien line yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
void GeserLINE (LINE * L, float deltaX, float deltaY) {
   Geser(&PAwal(*L), deltaX, deltaY);
   Geser(&PAkhir(*L), deltaX, deltaY);
}
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (LINE L1, LINE L2) {
   if (Gradien(L1) * Gradien(L2) == -1) {
      return true;
   } else {
      return false;
   }
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua line saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
boolean IsSejajar (LINE L1, LINE L2) {
   if (Gradien(L1) == Gradien(L2)) {
      return true;
   } else {
      return false;
   }
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua line saling sejajar jika memiliki gradien yang sama */