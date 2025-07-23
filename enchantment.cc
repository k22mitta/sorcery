#include "enchantment.h"
#include <iostream>
#include <iomanip>

Enchantment::Enchantment(const std::string &name, int cost, std::unique_ptr<Minion> target)
    : Minion{name, cost, 0, 0}, target{std::move(target)} {}

CardType Enchantment::getType() const {
    return CardType::Enchantment;
}

void Enchantment::display(int line) const {
    if (line < 5) {
        switch (line) {
            case 0: std::cout << "|-------------------------------|"; break;
            case 1: std::cout << "| " << std::setw(25) << name << " | " << std::setw(3) << cost << " |"; break;
            case 2: std::cout << "|-------------------------------|"; break;
            case 3: std::cout << "|                   Enchantment |"; break;
            case 4: std::cout << "|-------------------------------|"; break;
        }
    } else if (line < 11) {
        target->display(line - 5);
    }
}



void Enchantment::setStatOverride(int atk, int def) {
    overrideStats = true;
    newAttack = atk;
    newDefense = def;
}

void Enchantment::setStatModifier(int atkDelta, int defDelta) {
    attackModifier = atkDelta;
    defenseModifier = defDelta;
}

Minion &Enchantment::getBase() {
    return *target;
}

