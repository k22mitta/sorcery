#include "enchantment.h"
#include <iostream>
#include <iomanip>

Enchantment::Enchantment(const std::string &name, int cost, std::unique_ptr<Minion> target)
    : Minion{name, cost, 0, 0}, target{std::move(target)} {}

CardType Enchantment::getType() const {
    return CardType::Enchantment;
}

void Enchantment::display(int line) const {
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

