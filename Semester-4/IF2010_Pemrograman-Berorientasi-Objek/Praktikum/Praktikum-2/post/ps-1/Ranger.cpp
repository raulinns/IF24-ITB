#include "Ranger.hpp"

Ranger::Ranger(const string& name, int hp, int grace, int arrows)
    : Elf(name, hp, grace), arrows(arrows) {}

Ranger::~Ranger() {}

void Ranger::describe() const {
    cout << "Ranger [" << this->name << "] | HP: " << this->hp << " | Grace: " << this->grace << " | Arrows: " << this->arrows << "\n";
}

void Ranger::shoot() {
    cout << this->name << " draws an arrow (grace: " << this->grace << ") and fires! Arrows left: " << this->arrows - 1 << "\n";
    this->arrows--;
}