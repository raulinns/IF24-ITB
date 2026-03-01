#include "list.h"
#include <stdio.h>
#include <stdlib.h>


List removeDuplicates(List l) {
    if (l == NIL) return NIL;
    if (isOneElmt((l))) return l;

    if (INFO(l) == INFO(NEXT(l))) {
        deleteX(&l, INFO(l));
        return removeDuplicates(l);
    } else {
        return konso(INFO(l), removeDuplicates(tail(l)));
    }
    
    return NIL;
}
