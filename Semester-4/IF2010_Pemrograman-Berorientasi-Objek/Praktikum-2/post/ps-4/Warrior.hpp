#pragma once
#include "Character.hpp"

class Warrior : virtual public Character {
    private:
        int strength;
    
    public:
        Warrior(string, string, int, int, int);
        virtual ~Warrior();

        void attack() const;
        int getStrength() const;
};

