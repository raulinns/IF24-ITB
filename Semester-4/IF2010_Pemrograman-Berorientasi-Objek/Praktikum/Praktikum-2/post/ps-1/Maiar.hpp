#pragma once
#include "Creature.hpp"
#include <iostream>

using namespace std;

class Maiar : protected Creature {
    protected:
        int power;
    
    public:
        Maiar(const string& name, int hp, int power);
        ~Maiar();

        virtual void describe() const;
        int getPower() const;
};