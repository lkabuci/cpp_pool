//
// Created by redone on 6/21/23.
//

#ifndef POOL_CHARACTER_HPP
#define POOL_CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

private:
    std::string name;
    AMateria *inventory[4];
    static int maxCount;

public:
    Character();

    Character(const Character &);

    Character &operator=(const Character &);

    virtual ~Character();

    Character(std::string name);

    virtual const std::string &getName() const;

    virtual void equip(AMateria *m);

    virtual void unequip(int idx);

    virtual void use(int idx, ICharacter &target);

};

#endif //POOL_CHARACTER_HPP
