#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx) {
    Address p = FIRST(l);
    int i = 0;
    
    while (i < idx) {
        p = NEXT(p);
        i++;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }

    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    Address p = FIRST(l);
    int idx = 0;

    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
        idx++;
    }

    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);

    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);

    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);

    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address loc = FIRST(*l);
            int i = 0;
            while (i < idx - 1) {
                loc = NEXT(loc);
                i++;
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = FIRST(*l);
    Address loc = NULL;
    
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    
    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address loc = FIRST(*l);
        int i = 0;
        while (i < idx - 1) {
            loc = NEXT(loc);
            i++;
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l) {
    printf("[");
    Address p = FIRST(l);

    while (p != NULL) {
        printf("%d", INFO(p));
        if (NEXT(p) != NULL) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
    int count = 0;
    Address p = FIRST(l);

    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p = FIRST(l1);

    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    
    return l3;
}