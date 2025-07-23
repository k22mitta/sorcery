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

class GiantStrength : public Enchantment {
public:
    GiantStrength(std::shared_ptr<Minion> target)
        : Enchantment("Giant Strength", 1, std::move(target)) {}

    int getAttack() const override { return target->getAttack() + 2; }
    int getDefence() const override { return target->getDefence() + 2; }
};

class MagicFatigue : public Enchantment {
public:
    MagicFatigue(std::shared_ptr<Minion> target)
        : Enchantment("Magic Fatigue", 0, std::move(target)) {}

    std::shared_ptr<Ability> getActivatedAbility() const override {
        auto base = target->getActivatedAbility();
        if (base) return std::make_shared<CostModifier>(base, +2);
        return nullptr;
    }
};

class Silence : public Enchantment {
public:
    Silence(std::shared_ptr<Minion> target)
        : Enchantment("Silence", 1, std::move(target)) {}

    std::shared_ptr<Ability> getActivatedAbility() const override { return nullptr; }
    std::shared_ptr<TriggeredAbility> getTriggeredAbility() const override { return nullptr; }

    void useAbility(Player &, Player &, int, int) override {
        throw std::runtime_error("This minion is silenced and cannot use abilities.");
    }
};

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

