#include "minion.h"
#include <iostream>
#include <iomanip>

Minion::Minion(const std::string &name, int cost, int atk, int def)
    : Card{name, cost}, atk{atk}, def{def} {}

CardType Minion::getType() const {
    return CardType::Minion;
}

void Minion::display(std::ostream &out) const {
    out << std::left << std::setw(20) << name << " | Cost: " << cost << " | ATK: " << atk << " | DEF: " << def;
    if (ability) out << " | Ability Cost: " << dynamic_cast<ActivatedAbility *>(ability.get())->getCost();
    out << std::endl;
}

int Minion::getAttack() const { return atk; }
int Minion::getDefense() const { return def; }
bool Minion::canAct() const { return actions > 0; }
void Minion::restoreAction() { actions = 1; }
void Minion::spendAction() { if (actions > 0) --actions; }

void Minion::setAbility(std::unique_ptr<Ability> a) { ability = std::move(a); }
Ability *Minion::getAbility() const { return ability.get(); }
