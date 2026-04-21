#include "Elf.hpp"

Elf::Elf(const string& name, int hp, int grace) 
    : Creature(name, hp), grace(grace) {}

Elf::~Elf() {}

void Elf::describe() const {
    cout << "Elf [" << this->name << "] | HP: " << this->hp << " | Grace: " << this->grace << "\n";
}

int Elf::getGrace() const {
    return this->grace;
}