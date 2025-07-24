#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "minion.h"
#include "ascii_graphics.h"

class Game;

class Spell : public Card {
public:
    Spell(const std::string &name, int cost, std::string description);
    CardType getType() const override;
    card_template_t display() const override;
    virtual void effect(Game *game, int targetPlayer = -1, int targetCard = -1) = 0;
};

class Banish : public Spell {
public:
    Banish();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

class Unsummon : public Spell {
public:
    Unsummon();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

class Recharge : public Spell {
public:
    Recharge();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

class Disenchant : public Spell {
public:
    Disenchant();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

class RaiseDead : public Spell {
public:
    RaiseDead();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

class Blizzard : public Spell {
public:
    Blizzard();
    void effect(Game *game, int targetPlayer = -1, int targetCard = -1) override;
};

#endif
