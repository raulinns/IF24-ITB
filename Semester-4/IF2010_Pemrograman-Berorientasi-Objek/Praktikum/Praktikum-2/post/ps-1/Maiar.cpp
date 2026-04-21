#include "Maiar.hpp"

Maiar::Maiar(const string& name, int hp, int power) 
    : Creature(name, hp), power(power) {}

Maiar::~Maiar() {}

void Maiar::describe() const {
    cout << "Maiar [" << this->name << "] | HP: " << this->hp << " | Power: " << this->power << "\n";
}

int Maiar::getPower() const {
    return this->power;
}