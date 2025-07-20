#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

enum class CardType { Minion, Spell, Ritual, Enchantment };

class Card {
protected:
    std::string name;
    int cost;

public:
    Card(const std::string &name, int cost);
    virtual ~Card() = default;

    virtual CardType getType() const = 0;
    virtual void display(std::ostream &out) const = 0;
    std::string getName() const;
    int getCost() const;
};

#endif
