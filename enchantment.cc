#include "enchantment.h"
#include <iostream>
#include <iomanip>

Enchantment::Enchantment(const std::string &name, int cost, std::unique_ptr<Minion> target)
    : Minion{name, cost, 0, 0}, target{std::move(target)} {}

CardType Enchantment::getType() const {
    return CardType::Enchantment;
}

void Enchantment::display(std::ostream &out) const {
    target->display(out);
    out << "| Enchantment applied: " << name << "\n";
}

int Enchantment::getAttack() const {
    if (overrideStats) return newAttack;
    return target->getAttack() + attackModifier;
}

int Enchantment::getDefense() const {
    if (overrideStats) return newDefense;
    return target->getDefense() + defenseModifier;
}

bool Enchantment::canAct() const {
    return target->canAct();
}

void Enchantment::restoreAction() {
    target->restoreAction();
}

void Enchantment::spendAction() {
    target->spendAction();
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

