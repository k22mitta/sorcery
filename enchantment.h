#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "minion.h"
#include <memory>

class Enchantment : public Minion {
    std::unique_ptr<Minion> target;
    int attackModifier = 0;
    int defenseModifier = 0;
    bool overrideStats = false;
    int newAttack = 0;
    int newDefense = 0;

public:
    Enchantment(const std::string &name, int cost, std::unique_ptr<Minion> target);

    CardType getType() const override;
    void display(std::ostream &out) const override;

    int getAttack() const override;
    int getDefense() const override;
    void restoreAction() override;
    bool canAct() const override;
    void spendAction() override;

    void setStatOverride(int atk, int def);
    void setStatModifier(int atkDelta, int defDelta);

    Minion &getBase();
};

#endif
