#ifndef SPELL_H
#define SPELL_H

#include "card.h"

class Game;

class Spell : public Card {
public:
    Spell(const std::string &name, int cost);
    CardType getType() const override;
    virtual void effect(Game &game, int targetPlayer = -1, int targetCard = -1) = 0;
};

class Banish : public Spell {
public:
    Banish();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

class Unsummon : public Spell {
public:
    Unsummon();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

class Recharge : public Spell {
public:
    Recharge();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

class Disenchant : public Spell {
public:
    Disenchant();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

class RaiseDead : public Spell {
public:
    RaiseDead();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

class Blizzard : public Spell {
public:
    Blizzard();
    void display(int line) const override;
    void effect(Game &game, int targetPlayer = -1, int targetCard = -1) override;
};

#endif
