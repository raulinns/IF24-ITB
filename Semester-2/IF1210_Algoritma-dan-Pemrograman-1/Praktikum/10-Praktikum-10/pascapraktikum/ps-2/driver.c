#include "listlinier.h"
#include <stdio.h>

/* I.S. l terdefinisi, mungkin kosong */
/* F.S. List l diatur ulang sehingga semua bilangan ganjil muncul sebelum bilangan genap */
/*      dengan mempertahankan urutan relatif dalam setiap kelompok */
void separateOddEven(List *l) {
  Address p = FIRST(*l);
  List lSep;
  CreateList(&lSep);
  int i = 0;

  if (!(isEmpty(*l))) {
    while (p != NULL) {
      if (INFO(p) % 2 == 1) {
        insertAt(&lSep, INFO(p), i);
        i++;
      }

      p = NEXT(p);
    }

    p = FIRST(*l);
    while (p != NULL) {
      if (INFO(p) % 2 == 0) {
        insertAt(&lSep, INFO(p), i);
        i++;
      }

      p = NEXT(p);
    }

    p = FIRST(*l);
    while (p != NULL) {
      int temp;
      deleteFirst(l, &temp);
      
      p = NEXT(p);
    }

    p = FIRST(*l);
    Address pSep = FIRST(lSep);
    while (pSep != NULL) {
      insertLast(l, INFO(pSep));
      pSep = NEXT(pSep);    
    }
  }
}


int main() {
  int temp;
  List l;
  CreateList(&l);

  for (int i = 0; i < 5; i++) {
    scanf("%d", &temp);
    insertLast(&l, temp);
  }
  displayList(l);

  separateOddEven(&l);
  displayList(l);
  return 0;
}