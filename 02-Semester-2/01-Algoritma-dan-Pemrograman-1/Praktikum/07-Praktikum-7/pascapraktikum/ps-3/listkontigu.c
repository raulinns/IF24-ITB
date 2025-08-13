#include <stdio.h>
#include "listkontigu.h"

void CreateList(ListKontigu *l){
    for (int i = 0; i < CAPACITY; i++)
    {
        l->contents[i] = MARK;
    }
}

int firstIdx(ListKontigu l) {
    for (int i = 0; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK)
        {
            return i; // Indeks fisik elemen valid pertama
        }
    }
    return IDX_UNDEF; // Tidak ada elemen valid (list kosong)
}

int lastIdx(ListKontigu l) {
    for (int i = CAPACITY - 1; i >= 0; i--) {
        if (ELMT(l, i) != MARK)
        {
            return i; // Indeks fisik elemen valid terakhir
        }
    }
    return IDX_UNDEF; // Tidak ada elemen valid (list kosong)
}

int listLength(ListKontigu l){ // Mungkin bisa ngebug jika lebih dari capacity
    int first = firstIdx(l);
    if (first == IDX_UNDEF) // List kosong
    {
        return 0;
    }
    
    return (lastIdx(l)- first + 1); // Jika list tidak kosong
}

ElType getElmt(ListKontigu l, int i){
    int first = firstIdx(l);
    return l.contents[i + first];
}

void setElmt(ListKontigu *l, int i, ElType val){
    int first = firstIdx(*l);
    l->contents[i + first] = val;
}

boolean isIdxValid(int i){
    if (i >= IDX_MIN && i < CAPACITY)
    {
        return 1;
    }
    return 0;
}

boolean isIdxEff(ListKontigu l, int i){
    if (isEmpty(l))
    {
        return 0;
    }
    
    if (i >= firstIdx(l) && i <= lastIdx(l))
    {
        return 1;
    }
    return 0;
}

boolean isEmpty(ListKontigu l){
    if (firstIdx(l) == IDX_UNDEF)
    {
        return 1;
    }
    return 0;    
}

boolean isFull(ListKontigu l){
    if (listLength(l) == CAPACITY)
    {
        return 1;
    }
    return 0;
}

void readList(ListKontigu *l){
    int n;
    CreateList(l);

    scanf("%d", &n);

    while (n < 0 || n > CAPACITY)
    {
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l->contents[i]);
    }
}

void printList(ListKontigu l){
    printf("[");
    int first = firstIdx(l);
    if (first != IDX_UNDEF)
    {
        for (int i = first; i <= lastIdx(l); i++)
        {
            if (i == first)
            {
                printf("%d", l.contents[i]);
            }
            else
            {
                printf(",%d", l.contents[i]);
            }
        }
    }
    printf("]");
}

boolean isListEqual(ListKontigu l1, ListKontigu l2){
    if (listLength(l1) != listLength(l2))
    {
        return 0;
    }
    else // Jika panjang list sama
    {
        if (listLength(l1) == 0) // Kedua list kosong pasti sama
        {
            return 1;
        }
        
        int firstl1 = firstIdx(l1);
        int firstl2 = firstIdx(l2);
        for (int i = 0; i < listLength(l1); i++)
        {
            if (l1.contents[i + firstl1] != l2.contents[i + firstl2])
            {
                return 0;
            }
        }
        return 1; // Jika semua elemen sudah dicek dan sama
    }    
}

int indexOf(ListKontigu l, ElType val){
    if (isEmpty(l)) // Jika list kosong
    {
        return IDX_UNDEF;
    }
    
    for (int i = firstIdx(l); i <= lastIdx(l); i++)
    {
        if (l.contents[i] == val)
        {
            return i - firstIdx(l);
        }
    }
    return IDX_UNDEF;    
}

void copyList(ListKontigu lIn, ListKontigu *lOut){
    CreateList(lOut);
    int firstlIn = firstIdx(lIn);
    for (int i = 0; i < listLength(lIn); i++)
    {
        lOut->contents[i] = lIn.contents[i + firstlIn];
    }
}

void shiftBlock(ListKontigu *l, int startPhys, int endPhys, int delta){
    if (delta > 0)
    {
        for (int i = endPhys; i >= startPhys; i--)
        {
            l->contents[i+delta] = l->contents[i];
        }
        for (int i = startPhys; i <= startPhys + (delta-1); i++)
        {
            l->contents[i] = MARK;
        }
    }
    else if (delta < 0)
    {
        for (int i = startPhys; i <= endPhys; i++)
        {
            l->contents[i+delta] = l->contents[i];
        }
        for (int i = endPhys - (-delta-1); i <= endPhys; i++)
        {
            l->contents[i] = MARK;
        }        
    }
}

void insertFirst(ListKontigu *l, ElType val){
    int first = firstIdx(*l);
    int last = lastIdx(*l);
    if (first == IDX_UNDEF) // List kosong
    {
        l->contents[0] = val;
    }
    else
    {
        if (first == 0) // Berarti tidak ada ruang 1 elemen di kiri firstEl
        {
            shiftBlock(l, first, last, 1);
            l->contents[0] = val;
        }
        else
        {
            l->contents[first-1] = val;
        }        
    } 
}

void insertLast(ListKontigu *l, ElType val){
    int first = firstIdx(*l);
    int last = lastIdx(*l);
    if (first == IDX_UNDEF)
    {
        l->contents[0] = val;
    }
    else
    {
        if (last != CAPACITY-1) // Berarti ada ruang minimum 1 elemen di kanan lastEl
        {
            l->contents[last + 1] = val;
        }
        else
        {
            shiftBlock(l, first, last, -1);
            l->contents[CAPACITY-1] = val;
        }        
    } 
}

void insertAt(ListKontigu *l, ElType val, int i){
    int first = firstIdx(*l);
    int last = lastIdx(*l);

    if (first == -1) // List kosong
    {
        l->contents[0] = val;
    }
    else if (i == 0)
    {
        insertFirst(l, val);
    }
    else if (i == listLength(*l))
    {
        insertLast(l, val);
    }
    else // List tidak kosong
    {
        if (last != CAPACITY-1) // Ada ruang di kanan, insert di tengah2
        {
            shiftBlock(l, first + i, last, 1);
            l->contents[first + i] = val;
        }
        else // Ada ruang di kiri karena list tidak mungkin penuh, insert di tengah2 maka sisanya digeser ke kiri
        {
            shiftBlock(l, first, first + i - 1, -1);
            l->contents[first + i - 1] = val;
        }
    }
}

void deleteFirst(ListKontigu *l, ElType *val){
    int first = firstIdx(*l);

    *val = l->contents[first];
    l->contents[first] = MARK;
}

void deleteLast(ListKontigu *l, ElType *val){
    int last = lastIdx(*l);

    *val = l->contents[last];
    l->contents[last] = MARK;
}

void deleteAt(ListKontigu *l, int i, ElType *val){
    int first = firstIdx(*l);
    int last = lastIdx(*l);

    *val = l->contents[first + i];
    shiftBlock(l, first + i + 1, last, -1);
}

void concat(ListKontigu l1, ListKontigu l2, ListKontigu *l3){
    CreateList(l3);
    int firstl1 = firstIdx(l1);
    int lastl1 = lastIdx(l1);
    int lengthl1 = listLength(l1);
    int firstl2 = firstIdx(l2);
    int lastl2 = lastIdx(l2);
    int lengthl2 = listLength(l2);

    for (int i = 0; i < lengthl1; i++)
    {
        l3->contents[i] = l1.contents[i + firstl1];
    }
    for (int i = lengthl1; i < lengthl1 + lengthl2; i++)
    {
        l3->contents[i] = l2.contents[i - lengthl1 + firstl2];
    }
}