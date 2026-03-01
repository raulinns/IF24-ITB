#include "Paper.hpp"
int main() {
//     Paper a('A');
//     a.fold();
//     a.fold();
//     return 0;

//     ctor A
// ctor B
// ctor C
// cctor C
// fold A(1)
// fold B(1)
// fold C(1)
// glue C
// fold C(2)
// dtor A
// setName C => X
// fold C(1)
// glue C
// fold C(2)
// dtor C
// dtor X
// dtor B

    Paper* a;

    a = new Paper('A');
    Paper b('B');
    Paper c('C');
    Paper d(c);

    a->fold();
    b.fold();
    c.fold();
    c.glue();
    delete a;
    c.setName('X');
    d.fold();
    d.glue();
}