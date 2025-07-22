#ifndef MINION_H
#define MINION_H

#include "ability.h"
#include "card.h"

class Minion : public Card {
    int atk;
    int def;
    int actions;
    std::unique_ptr<Ability> ability;

public:
    Minion(const std::string &name, int cost, int atk, int def);

    CardType getType() const override;
    void display(int line) const override;

    int getAttack() const;
    int getDefense() const;
    void setAttack(int val);
    void setDefense(int val);
    void modifyStats(int atkDelta, int defDelta);

    bool canAct() const;
    void restoreAction();
    void spendAction();

    virtual Ability *getAbility();
    void setAbility(std::unique_ptr<Ability> ability);
};

#endif
