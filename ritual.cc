#include "ritual.h"
#include <iostream>
#include <iomanip>

Ritual::Ritual(const std::string &name, int cost, int activationCost, int charges)
    : Card{name, cost}, activationCost{activationCost}, charges{charges} {}

CardType Ritual::getType() const { return CardType::Ritual; }

void Ritual::display(std::ostream &out) const {
    out << "|-------------------------------|\n";
    out << "| " << std::setw(25) << std::left << name << " | " << std::setw(2) << cost << " |\n";
    out << "|-------------------------------|\n";
    out << "| Ritual                        |\n";
    out << "|-------------------------------|\n";
    out << "| " << std::setw(2) << activationCost << " | <trigger description here> |\n";
    out << "|                               |\n";
    out << "| ------                       |\n";
    out << "|   " << std::setw(2) << charges << "                         |\n";
    out << "|-------------------------------|\n";
}

int Ritual::getActivationCost() const { return activationCost; }
int Ritual::getCharges() const { return charges; }
void Ritual::addCharges(int n) { charges += n; }
bool Ritual::canActivate() const { return charges >= activationCost; }
void Ritual::consumeCharge() { if (canActivate()) charges -= activationCost; }

DarkRitual::DarkRitual()
    : Ritual{"Dark Ritual", "At the start of your turn, gain 1 magic", 0, 1, 5} {}

DarkRitual::trigger(Game &game) {
    // TODO
    std::cout << "Dark Ritual Triggered" << std::endl;
}

AuraOfPower::AuraOfPower()
    : Ritual{"Dark Ritual", "Whenever a minion enters under your control, it gains +1/+1", 1, 1, 4} {}

AuraOfPower::trigger(Game &game) {
    // TODO
    std::cout << "Dark Ritual Triggered" << std::endl;
}

StandStill::StandStill()
    : Ritual{"Dark Ritual", "At the start of your turn, gain 1 magic", 3, 2, 4} {}

StandStill::trigger(Game &game) {
    // TODO
    std::cout << "Dark Ritual Triggered" << std::endl;
}