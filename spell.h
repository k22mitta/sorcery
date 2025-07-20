#ifndef SPELL_H
#define SPELL_H

#include "card.h"

class Game;

class Spell : public Card {
public:
    Spell(const std::string &name, const std::string &description, int cost);
    CardType getType() const override;
    void display(std::ostream &out) const override;
    virtual void effect(Game &game, int targetPlayer = -1, int targetCard = -1) = 0;
};

#endif
