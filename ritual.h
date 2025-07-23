#ifndef RITUAL_H
#define RITUAL_H

#include "game.h"
#include "card.h"

class Ritual : public Card {
protected:
    int activationCost;
    int charges;

public:
    Ritual(const std::string &name, int cost, int activationCost, int charges);

    CardType getType() const override;
    int getActivationCost() const;
    int getCharges() const;
    void addCharges(int n);
    bool canActivate() const;
    void consumeCharge();

    virtual void trigger(Game &game) = 0;
};

class DarkRitual : public Ritual {
public:
    DarkRitual();
    void display(int line) const override;
    void trigger(Game &game) override;
};

class AuraOfPower : public Ritual {
public:
    AuraOfPower();
    void display(int line) const override;
    void trigger(Game &game) override;
};

class StandStill : public Ritual {
public:
    StandStill();
    void display(int line) const override;
    void trigger(Game &game) override;
};

#endif
