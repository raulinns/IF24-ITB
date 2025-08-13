#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (ElType*) malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;

 }
 /* I.S. l sembarang, capacity > 0 */
 /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
 
 void dealocateList(ListDin *l) {
    free(BUFFER(*l));
    BUFFER(*l) = NULL;
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
 }
 /* I.S. l terdefinisi; */
 /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
 
 /* ********** SELEKTOR (TAMBAHAN) ********** */
 /* *** Banyaknya elemen *** */
 int listLength(ListDin l) {
    return NEFF(l);
 }
 /* Mengirimkan banyaknya elemen efektif list */
 /* Mengirimkan nol jika list l kosong */
 /* *** Daya tampung container *** */
 
 /* *** Selektor INDEKS *** */
 IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
 }
 /* Prekondisi : List l tidak kosong */
 /* Mengirimkan indeks elemen l pertama */

 IdxType getLastIdx(ListDin l) {
    return NEFF(l) - 1;
 }
 /* Prekondisi : List l tidak kosong */
 /* Mengirimkan indeks elemen l terakhir */
 
 /* ********** Test Indeks yang valid ********** */

 boolean isIdxValid(ListDin l, IdxType i) {
    return (IDX_MIN <= i && i < CAPACITY(l));
 }
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff(ListDin l, IdxType i) {
    return (IDX_MIN <= i && i < NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
    if (NEFF(l) == 0) return TRUE;
    else return FALSE; 
}

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
    if (listLength(l) == CAPACITY(l)) return TRUE;
    else return FALSE;
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
    int N;
    do {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY(*l));
    NEFF(*l) = N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

void printList(ListDin l) {
    printf("[");
    for (int i = 0; i < NEFF(l); i++) {
        if (i != 0) {
            printf(",");
        }
        printf("%d", ELMT(l, i));
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin lResult;
    CreateListDin(&lResult, CAPACITY(l1));
    NEFF(lResult) = listLength(l1); 
    if (plus == TRUE) {
        for (int i = 0; i < NEFF(l1); i++) {
            ELMT(lResult, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else if (plus == FALSE) {
        for (int i = 0; i < NEFF(l1); i++) {
            ELMT(lResult, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return lResult;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
    if (listLength(l1) != listLength(l2)) {
        return FALSE;
    } else {
        for (int i = 0; i < NEFF(l1); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
    for (int i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
    *min = ELMT(l, 0);
    *max = ELMT(l, 0);
    for (int i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
        if (*max < ELMT(l, i)) {
            *max = ELMT(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (int i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l) {
    ElType sum = 0;
    for (int i = 0; i < NEFF(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
    int count = 0;
    for (int i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            count++;
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
    for (int i = 0; i < listLength(*l) - 1; i++) {
        for (int j = 0; j < listLength(*l) - i - 1; j++) {
            if (asc == TRUE) {
                if (ELMT(*l, j) > ELMT (*l, j + 1)) {
                    ElType temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            } else if (asc == FALSE) {
                if (ELMT(*l, j) < ELMT(*l, j + 1)) {
                    ElType temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
    int length = listLength(*l);
    ELMT(*l, length) = val;
    NEFF(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, listLength(*l) - 1);
    ELMT(*l, listLength(*l) - 1) = 0;
    NEFF(*l)--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
    CAPACITY(*l) -= num;
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l) {
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */