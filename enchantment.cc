#include "enchantment.h"
#include <iostream>
#include <iomanip>

Enchantment::Enchantment(const std::string &name, int cost, std::string description, std::unique_ptr<Minion> target)
    : Minion{name, cost, description, 0, 0}, target{std::move(target)} {}

CardType Enchantment::getType() const {
    return CardType::Enchantment;
}

card_template_t Enchantment::display() const {
    if (overrideStats || attackModifier != 0 || defenseModifier != 0) {
        int attack = overrideStats ? newAttack : target->getAttack() + attackModifier;
        int defence = overrideStats ? newDefense : target->getDefense() + defenseModifier;

        return display_enchantment_attack_defence(
            getName(),
            getCost(),
            getDescription(),
            to_string(attack),
            to_string(defence)
        );
    } else {
        return display_enchantment(
            getName(),
            getCost(),
            getDescription()
        );
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

