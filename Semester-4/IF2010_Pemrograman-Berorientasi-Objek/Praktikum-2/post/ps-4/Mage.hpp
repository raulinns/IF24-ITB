#pragma once
#include "Character.hpp"

class Mage : virtual public Character {
    private:
        int mana;
    
    public:
        Mage(string, string, int, int, int);
        virtual ~Mage();

        void castSpell() const;
        int getMana() const;
};

