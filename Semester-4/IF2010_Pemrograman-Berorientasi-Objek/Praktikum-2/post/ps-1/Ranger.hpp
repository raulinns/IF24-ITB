#pragma once

#include "Elf.hpp"
#include <iostream>

using namespace std;

class Ranger : public Elf {
    protected:
        int arrows;
    
    public:
        Ranger(const string& name, int hp, int grace, int arrows);
        ~Ranger();

        virtual void describe() const;
        void shoot();
};