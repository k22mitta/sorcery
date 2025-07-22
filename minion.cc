#include "minion.h"
#include <iostream>
#include <iomanip>

Minion::Minion(const std::string &name, int cost, int atk, int def)
    : Card{name, cost}, atk{atk}, def{def}, actions{0} {}

CardType Minion::getType() const { return CardType::Minion; }

void Minion::display(int line) const {

}

int Minion::getAttack() const { return atk; }
int Minion::getDefense() const { return def; }
void Minion::setAttack(int val) { atk = val; }
void Minion::setDefense(int val) { def = val; }
void Minion::modifyStats(int atkDelta, int defDelta) { atk += atkDelta; def += defDelta; }

bool Minion::canAct() const { return actions > 0; }
void Minion::restoreAction() { actions = 1; }
void Minion::spendAction() { if (actions > 0) --actions; }

Ability* Minion::getAbility() { return ability.get(); }
void Minion::setAbility(std::unique_ptr<Ability> ability) { this -> ability = std::move(ability); }
