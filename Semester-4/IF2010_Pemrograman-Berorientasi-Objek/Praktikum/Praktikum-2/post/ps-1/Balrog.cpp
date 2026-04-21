#include "Balrog.hpp"

Balrog::Balrog(const string& name, int hp, int power, string whipName) 
    : Maiar(name, hp, power), whipName(whipName) {}

Balrog::~Balrog() {}

void Balrog::describe() const {
    cout << "Balrog [" << this->name << "] | HP: " << this->hp << " | Power: " << this->power << " | Whip: " << this->whipName << "\n";
}

void Balrog::rage() const {
    cout << this->name << " cracks " << this->whipName << " with " << this->power << " power!\n";
}