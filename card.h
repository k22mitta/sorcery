#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include "ascii_graphics.h"

enum class CardType { Minion, Spell, Ritual, Enchantment };

class Card {
protected:
    std::string name;
    int cost;
    std::string description;

public:
    Card(const std::string &name, int cost, std::string description);
    virtual ~Card() = default;

    virtual CardType getType() const = 0;
    virtual card_template_t display() const = 0;
    std::string getName() const;
    int getCost() const;
    const std::string &getDescription() const;
};

#endif
