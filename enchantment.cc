#include "enchantment.h"
#include <iostream>
#include <iomanip>

Enchantment::Enchantment(const std::string &name, int cost, std::unique_ptr<Card> target)
    : Card{name, cost}, target{std::move(target)} {}

CardType Enchantment::getType() const {
    return CardType::Enchantment;
}

void Enchantment::display(std::ostream &out) const {
    target->display(out);
    out << "| Enchantment applied: " << name << "\n";
}

int Enchantment::getAttack() const {
    if (overrideStats) return newAttack;
    Minion *minion = dynamic_cast<Minion *>(target.get());
    if (minion) return minion->getAttack() + attackModifier;
    return 0;
}

int Enchantment::getDefense() const {
    if (overrideStats) return newDefense;
    Minion *minion = dynamic_cast<Minion *>(target.get());
    if (minion) return minion->getDefense() + defenseModifier;
    return 0;
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

Card &Enchantment::getBase() {
    return *target;
}
