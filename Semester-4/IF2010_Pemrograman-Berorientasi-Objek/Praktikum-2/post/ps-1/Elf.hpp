#pragma once
#include "Creature.hpp"
#include <iostream>

using namespace std;

class Elf : public Creature {
    protected:
        int grace;
    
    public:
        Elf(const string& name, int hp, int grace);
        ~Elf();

        virtual void describe() const;
        int getGrace() const;
};