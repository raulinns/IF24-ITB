#pragma once
#include "Maiar.hpp"
#include <iostream>

using namespace std;

class Wizard : private Maiar {
    protected:
        string staffName;
    
    public:
        Wizard(const string& name, int hp, int power, string staffName);
        ~Wizard();

        virtual void describe() const;
        void cast() const;
};