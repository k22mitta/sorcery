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
void DarkRitual::trigger(Game &game) {
    std::cout << "Dark Ritual Triggered — Gain 1 magic" << std::endl;
    Player &owner = game.getCurrentPlayer();
    owner.changeMagic(1);
}

AuraOfPower::AuraOfPower()
    : Ritual{"Aura of Power", 1, 1, 4} {}
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
void StandStill::trigger(Game &game) {
    std::cout << "Standstill Triggered — Destroy last minion" << std::endl;
    Player &opponent = game.getOtherPlayer();
    if (!opponent.getBoard().empty()) {
        auto &board = opponent.getBoard();
        opponent.getGraveyard().emplace_back(std::move(board.back()));
        board.pop_back();
    }
}

void DarkRitual::display(int line) const {
    switch (line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Dark Ritual            |" << std::setw(5) << cost << " |";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3:
            std::cout << "|                        Ritual |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|  " << std::setw(3) << activationCost << " |At the start of your    |";
            break;
        case 6:
            std::cout << "|------ turn, gain 1 magic      |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|                         ------|";
            break;
        case 9:
            std::cout << "|                         |" << std::setw(4) << charges << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}

void AuraOfPower::display(int line) const {
    switch (line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Aura of Power          |" << std::setw(5) << cost << " |";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3:
            std::cout << "|                        Ritual |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|  " << std::setw(3) << activationCost << " |Whenever a minion enters|";
            break;
        case 6:
            std::cout << "|------ play under your control,|";
            break;
        case 7:
            std::cout << "|       it gains +1/+1          |";
            break;
        case 8:
            std::cout << "|                         ------|";
            break;
        case 9:
            std::cout << "|                         |" << std::setw(4) << charges << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}

void StandStill::display(int line) const {
    switch (line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Standstill             |" << std::setw(5) << cost << " |";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3:
            std::cout << "|                        Ritual |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|  " << std::setw(3) << activationCost << " |Whenever a minion       |";
            break;
        case 6:
            std::cout << "|------ enters play, destroy it |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|                         ------|";
            break;
        case 9:
            std::cout << "|                         |" << std::setw(4) << charges << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
