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

void Banish::display(int line) const {

}
void Unsummon::display(int line) const {

}
void Recharge::display(int line) const {

}
void Disenchant::display(int line) const {

}
void RaiseDead::display(int line) const {

}
void Blizzard::display(int line) const {

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