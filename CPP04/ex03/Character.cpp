//
// Created by redone on 6/21/23.
//

#include "Character.hpp"

int Character::maxCount = 4;

Character::Character() : name("None") {
    for (int i = 0; i < maxCount; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string name) : name(name) {
    for (int i = 0; i < maxCount; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &other) {
    for (int i = 0; i < maxCount; ++i) {
        inventory[i] = NULL;
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character &Character::operator=(const Character &other) {
    if (this == &other)
        return *this;
    name = other.name;
    for (int i = 0; i < maxCount; ++i) {
        delete inventory[i];
    }
    for (int i = 0; i < maxCount; ++i) {
        inventory[i] = NULL;
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < maxCount; ++i) {
        delete inventory[i];
    }
}

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < maxCount; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < maxCount) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < maxCount && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
