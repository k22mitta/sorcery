#include "spell.h"
#include <iostream>
#include <iomanip>

Spell::Spell(const std::string &name, const std::string &description, int cost) : Card{name, description, cost} {}

CardType Spell::getType() const { return CardType::Spell; }

void Spell::display(std::ostream &out) const {
    out << "|-------------------------------|\n";
    out << "| " << std::setw(25) << std::left << name << " | " << std::setw(2) << cost << " |\n";
    out << "|-------------------------------|\n";
    out << "| " << std::setw(29) << "Spell" << "|\n";
    out << "|-------------------------------|\n";
    out << "| <effect description here>     |\n";
    out << "|                               |\n";
    out << "|                               |\n";
    out << "|-------------------------------|\n";
}
