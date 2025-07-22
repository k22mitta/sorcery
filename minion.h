#ifndef MINION_H
#define MINION_H

#include "card.h"
#include "ability.h"
#include <memory>

class Minion : public Card {
    int atk, def;
    int actions = 1;
    std::unique_ptr<Ability> ability;

public:
    Minion(const std::string &name, int cost, int atk, int def);

    CardType getType() const override;
    void display(std::ostream &out) const override;

    int getAttack() const;
    int getDefense() const;
    bool canAct() const;
    void restoreAction();
    void spendAction();

    void setAbility(std::unique_ptr<Ability> a);
    Ability *getAbility() const;
};

#endif
