#include "polynomial.h"

/* ==================== Polynomial Operations ==================== */
 
 /* Konstruktor */
 void CreatePolynomial(Polynomial *p) {
    for (int i = 0; i <= MAX_DEGREE; i++) {
        p->coeff[i] = 0;
    }
    p->degree = 0;
 }
 /**
  * I.S. -
  * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi dengan 0.0
  * dan degree juga diinisialisasi dengan 0
  */
 
 void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size) {
     CreatePolynomial(p);
     for (int i = 0; i < size; i++) {
         p->coeff[i] = coeffArray[i];
    }
    
    for (int i = size - 1; i >= 0; i--) {
         if (p->coeff[i] != 0) {
            p->degree = i;
            return;
        }
    }
    p->degree = 0;
 }
 /**
  * I.S. CoeffArray adalah array of coefficients yang terdefinisi, 
  * size adalah ukuran dari coeffArray yang terdefinisi
  * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi berdasarkan coeffArray
  * dan degree diinisialisasikan dengan index tertinggi dari elemen coeffArray yang tidak nol
  */
 
 /* Selektor */
 int GetCoefficient(Polynomial *p, int exponent) {
    int exp = p->coeff[exponent];
    return exp;
 }
 /**
  * Mengembalikan nilai koefisien pada suku dengan eksponen = exponent
  */
 
 int GetDegree(Polynomial *p) {
    for (int i = MAX_DEGREE; i >= 0; i--) {
        if (p->coeff[i] != 0) {
            return i;
        }
    }
    return 0;
 }
 /**
  * Mengembalikan derajat tertinggi dari polynomial dengan koefisien tak nol
  */
 
 int Evaluate(Polynomial *p, int x) {
    int eval = 0;
    for (int i = 0; i <= GetDegree(p); i++) {
        eval += pow(x, i) * p->coeff[i];
    }
    return eval;
 }
 /**
  * Mengembalikan hasil evaluasi polynomial p dengan masukan x
  * Contoh: 
  * p = 3x^2 + 3x + 1
  * Evaluate(p, 1) = 3(1^2) + 3(1) + 1 = 7
  */
 
 /* Mutator */
 void SetCoefficient(Polynomial *p, int exponent, int coefficient) {
    if (exponent < 0 || exponent > MAX_DEGREE) return;  
    
    p->coeff[exponent] = coefficient;
    p->degree = GetDegree(p);
 }
 /**
  * I.S. Polynomial p, exponent, dan coefficient terdefinisi
  * F.S. Polynomial p diupdate dengan koefisien baru (coefficient)
  * pada suku dengan eksponen yang diberikan (exponent)
  */
 
 /* Operasi Baca/Tulis */
 void ReadPolynomial(Polynomial *p) {
    CreatePolynomial(p);
    int size;
    do {
        scanf("%d", &size);
    } while (size < 0 || size > MAX_DEGREE);

    for (int i = 0; i < size; i++) {
        scanf("%d", &p->coeff[i]);
    }
    p->degree = GetDegree(p);
}
 /**
  * I.S. Polynomial p belum terdefinisi
  * F.S. Polynomial p terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input
  * - Meminta input size yang merupakan banyak koefisien yang akan dimasukkan (dari koefisien 0)
  * - Meminta input koefisien sebanyak size dan menginisialisasi p berdasarkan nilai ini (dari koefisien 0)
  */
 
 /* Operator Aritmatika */
 void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    CreatePolynomial(result);
    for (int i = 0; i <= MAX_DEGREE; i++) {
        result->coeff[i] = p1->coeff[i] + p2->coeff[i];
    }
    result->degree = GetDegree(result);
 }
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Hasil penjumlahan p1 dan p2 (p1 + p2) disimpan di polynomial result
  */
 
 void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    CreatePolynomial(result);

    for (int i = 0; i <= MAX_DEGREE; i++) {
        result->coeff[i] = p1->coeff[i] - p2->coeff[i];
    }
    result->degree = GetDegree(result);
 }
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Hasil pengurangan p1 dan p2 (p1 - p2) disimpan di polynomial result
  */
 
 int IsEqual(Polynomial *p1, Polynomial *p2) {
    if (p1->degree != p2->degree) {
        return 0;
    } else {
        for (int i = 0; i <= p1->degree; i++) {
            if (p1->coeff[i] != p2->coeff[i]) {
                return 0;
            }
        }
        return 2;
    }
 }
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Mengembalikan 1 jika kedua polynomial adalah sama, dan 0 jika sebaliknya
  * Dua polynomial dianggap sama jika keduanya memiliki derajat yang sama dan semua koefisiennya bernilai sama
  */
 
 /* Operasi Lain */
 void PrintPolynomial(Polynomial *p) { // TERIMA KASIH WISE ATAS BANTUANNYA FORMATTING YANG INI, code yang sebelumnya di terminal udah cocok persis, tapi testcasenya dapet 90 gak dapet 100
    int printed = 1;
    for (int i = GetDegree(p); i >= 0; i--) {
        if (p->coeff[i] == 0) continue;

        if (printed == 0) {
            if (p->coeff[i] > 0) printf(" + ");
            else if (p->coeff[i] < 0) printf(" - "); 
        } else {
            if (p->coeff[i] < 0) printf("-");
            printed = 0;
        }

        int absC = abs(p->coeff[i]);
        if (absC != 1 || i == 0) {
            printf("%d", absC);
        } 
        if (i > 0) {
            printf("x");
            if (i > 1) printf("^%d", i);
        }
    }
    if (printed == 1) printf("0");
    printf("\n");
 }
 /**
  * I.S. P terdefinisi
  * F.S. Polynomial p ditampilkan dengan aturan sebagai berikut:
  * - Elemen ditampilkan dari derajat paling tinggi ke derajat paling rendah
  * - Hanya tampilkan elemen dengan koefisien tak nol
  * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien positif, tidak perlu berikan tanda + di depan
  * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien negatif, tidak perlu berikan spasi antara tanda - dan suku (-x^n)
  * - Untuk suku yang bukan derajat tertinggi, tampilkan tanda + dan - dengan diberikan spasi (x^3 + 6x)
  * - Untuk koefisien 1, hanya tampilkan x^n (bukan 1x^n), kecuali untuk suku konstan
  * - Untuk koefisien -1, hanya tampilkan -x^n atau - x^n (bukan -1x^n dan - 1x^n), kecuali untuk suku konstan
  * - Untuk suku derajat 1, tampilkan x (bukan x^1)
  * - Untuk suku derajat 0, tampilkan koefisiennya saja
  * - Berikan newline (\n) di akhir baris
  * Contoh: -4x^3 + 3x^2 - 2x + 1
  */