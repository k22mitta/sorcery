#ifndef RITUAL_H
#define RITUAL_H

#include "card.h"

class Ritual : public Card {
    int activationCost;
    int charges;

public:
    Ritual(const std::string &name, int cost, int activationCost, int charges);

    CardType getType() const override;
    void display(std::ostream &out) const override;
    int getActivationCost() const;
    int getCharges() const;
    void addCharges(int n);
    bool canActivate() const;
    void consumeCharge();

    virtual void trigger(Game &game) = 0;
};

class DarkRitual : public Ritual {
public:
    void trigger(Game &game) override;
};

class AuraOfPower : public Ritual {
public:
    void trigger(Game &game) override;
};

class StandStill : public Ritual {
public:
    void trigger(Game &game) override;
};

#endif
