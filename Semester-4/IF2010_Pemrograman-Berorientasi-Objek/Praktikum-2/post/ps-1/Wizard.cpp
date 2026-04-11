#include "Wizard.hpp"

Wizard::Wizard(const string& name, int hp, int power, string staffName) 
    : Maiar(name, hp, power), staffName(staffName) {}

Wizard::~Wizard() {}

void Wizard::describe() const {
    cout << "Wizard [" << this->name << "] | HP: " << this->hp << " | Staff: " << this->staffName << "\n";
}

void Wizard::cast() const {
    cout << this->name << " channels " << this->power << " power through " << this->staffName << "!\n";
}