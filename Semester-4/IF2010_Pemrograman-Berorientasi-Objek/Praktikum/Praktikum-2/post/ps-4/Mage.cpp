#include "Mage.hpp"


Mage::Mage(string characterId, string name, int hp, int level, int mana)
    : Character(characterId, name, hp, level), mana(mana) {
        cout << "[CREATE] Mage " << this->name << " with " << this->mana << " mana ready\n";
    }
Mage::~Mage() {
    cout << "[DELETE] Mage " << this->name << " destroyed\n"; }

void Mage::castSpell() const {
    cout << "[CAST] " << this->name << " casts a spell using " << this->mana << " mana\n";
}

int Mage::getMana() const {
    return this->mana;
}