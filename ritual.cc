#include "ritual.h"
#include "minion.h"
#include <iostream>
#include <iomanip>

Ritual::Ritual(const std::string &name, int cost, int activationCost, int charges)
    : Card{name, cost}, activationCost{activationCost}, charges{charges} {}

CardType Ritual::getType() const { return CardType::Ritual; }

int Ritual::getActivationCost() const { return activationCost; }
int Ritual::getCharges() const { return charges; }
void Ritual::addCharges(int n) { charges += n; }
bool Ritual::canActivate() const { return charges >= activationCost; }
void Ritual::consumeCharge() { if (canActivate()) charges -= activationCost; }

DarkRitual::DarkRitual()
    : Ritual{"Dark Ritual", 0, 1, 5} {}
void DarkRitual::display(std::ostream &out) const {

}
void DarkRitual::trigger(Game &game) {
    std::cout << "Dark Ritual Triggered — Gain 1 magic" << std::endl;
    Player &owner = game.getCurrentPlayer();
    owner.changeMagic(1);
}

AuraOfPower::AuraOfPower()
    : Ritual{"Aura of Power", 1, 1, 4} {}
void AuraOfPower::display(std::ostream &out) const {

}
void AuraOfPower::trigger(Game &game) {
    std::cout << "Aura of Power Triggered — Buff all minions" << std::endl;
    Player &owner = game.getCurrentPlayer();
    for (auto& card : owner.getBoard()) {
        Minion *minion = dynamic_cast<Minion*>(card.get());
        if (minion) {
            minion->modifyStats(1, 1);
        }
    }
}

StandStill::StandStill()
    : Ritual{"Standstill", 3, 2, 4} {}
void StandStill::display(std::ostream &out) const {

}
void StandStill::trigger(Game &game) {
    std::cout << "Standstill Triggered — Destroy last minion" << std::endl;
    Player &opponent = game.getOtherPlayer();
    if (!opponent.getBoard().empty()) {
        auto &board = opponent.getBoard();
        opponent.getGraveyard().emplace_back(std::move(board.back()));
        board.pop_back();
    }
}