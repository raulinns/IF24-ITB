/* File: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include "boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    return (H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59);
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS; 
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
    int H, M, S;
    while (1) {
        scanf("%d %d %d", &H, &M, &S);
        if (IsTIMEValid(H, M, S)) {
            CreateTime(T, H, M, S);
            break;
        } else {
            printf("Jam tidak valid\n");
        }
    }
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   
void TulisTIME (TIME T){
    printf("%01d:%01d:%01d", Hour(T), Minute(T), Second(T));
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
    return (long)Hour(T) * 3600 + (long)Minute(T) * 60 + (long)Second(T);
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N){
    TIME T;
    long N1 = N % 86400;
    if (N1 < 0) {
        N1 += 86400;
    }
    Hour(T) = (int)(N1 / 3600);
    Minute(T) = (int)((N1 % 3600) / 60);
    Second(T) = (int)(N1 % 60);
    return T;
}
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
    return !TEQ(T1,T2);
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    long detik = TIMEToDetik(T);
    detik = (detik + 1) % 86400;
    return DetikToTIME(detik);
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
    long detik = TIMEToDetik(T);
    detik = (detik + N);
    return DetikToTIME(detik);
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
    long detik = TIMEToDetik(T);
    detik = (detik - 1);
     if (detik < 0) {
        detik += 86400;
    }
    return DetikToTIME(detik);
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
    long detik = TIMEToDetik(T);
    detik = (detik - N);
    return DetikToTIME(detik);
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    long detikAw = TIMEToDetik(TAw);
    long detikAkh = TIMEToDetik(TAkh);
    if (detikAkh >= detikAw) {
        return detikAkh - detikAw;
    } else {
        return (detikAkh + 86400) - detikAw;
    }
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

#endif