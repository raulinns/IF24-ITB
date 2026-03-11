#include "Layla.hpp"
#include "Tigreal.hpp"

int main() {
    Layla *l1 = new Layla(10, 1000);
    l1->useSkill();
    Layla *lClone1 = new Layla(*l1);
    l1->heal(5);

    Layla *l2 = new Layla(50, 200);
    l2->moveTo(15, 30);

    *l2 = *l1;

    Tigreal *t1 = new Tigreal(200, 10);
    t1->moveTo(5, 15);
    t1->taunt(10);
    Tigreal *tClone1 = new Tigreal(*t1);

    Tigreal *t2 = new Tigreal(400, 20);
    t2->sacredHammer();

    Tigreal *tClone2 = new Tigreal(*t2);
    t1->useSkill();
    t2->useSkill();

    Tigreal *t3 = new Tigreal(300, 15);
    t3->moveTo(10, 20);
    Tigreal *tClone3 = new Tigreal(*t3);
    t3->taunt(5);

    delete tClone3;
    delete l1;
    delete lClone1;
    delete l2;
    delete t3;
    delete tClone2;
    delete t2;
    delete tClone1;
    delete t1;

    return 0;
}
