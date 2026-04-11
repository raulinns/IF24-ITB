#include "Warrior.hpp"

Warrior::Warrior(string characterId, string name, int hp, int level, int strength)
    : Character(characterId, name, hp, level), strength(strength) {
        cout << "[CREATE] Warrior " << name << " with " << this->strength << " str ready\n";
    }

Warrior::~Warrior() {cout << "[DELETE] Warrior " << this->name << " destroyed\n"; }

void Warrior::attack() const {
    cout << "[ATTACK] " << this->name << " attacks with " << this->strength << " strength\n";
}

int Warrior::getStrength() const{
    return this->strength;
}