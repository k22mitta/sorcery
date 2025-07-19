#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "card.h"
#include "minion.h"
#include <memory>

class Enchantment : public Card {
    std::unique_ptr<Card> target;
    int attackModifier = 0;
    int defenseModifier = 0;
    bool overrideStats = false;
    int newAttack = 0;
    int newDefense = 0;

public:
    Enchantment(const std::string &name, int cost, std::unique_ptr<Card> target);

    CardType getType() const override;
    void display(std::ostream &out) const override;

    int getAttack() const;
    int getDefense() const;
    void setStatOverride(int atk, int def);
    void setStatModifier(int atkDelta, int defDelta);

    Card &getBase();
};

#endif
