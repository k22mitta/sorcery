#include "spell.h"
#include <iostream>
#include <iomanip>

Spell::Spell(const std::string &name, int cost) : Card{name, cost} {}

CardType Spell::getType() const { return CardType::Spell; }

Banish::Banish(): Spell{"Banish", 2} {}
Unsummon::Unsummon(): Spell{"Unsummon", 1}{}
Recharge::Recharge(): Spell{"Recharge", 1} {}
Disenchant::Disenchant(): Spell{"Disenchant", 1} {}
RaiseDead::RaiseDead(): Spell{"Raise Dead", 1} {}
Blizzard::Blizzard(): Spell{"Blizzard", 3} {}

void Banish::display(std::ostream &out) const {
    // TODO
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
void Unsummon::display(std::ostream &out) const {
    // TODO
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
void Recharge::display(std::ostream &out) const {
    // TODO
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
void Disenchant::display(std::ostream &out) const {
    // TODO
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
void RaiseDead::display(std::ostream &out) const {
    // TODO
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
void Blizzard::display(std::ostream &out) const {
    // TODO
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

void Banish::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}
void Unsummon::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}
void Recharge::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}
void Disenchant::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}
void RaiseDead::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}
void Blizzard::effect(Game &game, int targetPlayer, int targetCard) {
    // TODO
}