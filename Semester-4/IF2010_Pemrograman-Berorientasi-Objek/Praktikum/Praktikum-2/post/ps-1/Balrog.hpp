#pragma once
#include "Maiar.hpp"
#include <iostream>

using namespace std;

class Balrog : public Maiar {
    protected:
        string whipName;
    
    public:
        Balrog(const string& name, int hp, int power, string whipName);
        ~Balrog();

        virtual void describe() const;
        void rage() const;
};