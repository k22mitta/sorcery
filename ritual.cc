#include "ritual.h"
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
    // TODO
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
void DarkRitual::trigger(Game &game) {
    // TODO
    std::cout << "Dark Ritual Triggered" << std::endl;
}

AuraOfPower::AuraOfPower()
    : Ritual{"Aura of Power", 1, 1, 4} {}
void AuraOfPower::display(std::ostream &out) const {
    // TODO
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
void AuraOfPower::trigger(Game &game) {
    // TODO
    std::cout << "Aura of Power Triggered" << std::endl;
}

StandStill::StandStill()
    : Ritual{"Standstill", 3, 2, 4} {}
void StandStill::display(std::ostream &out) const {
    // TODO
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
void StandStill::trigger(Game &game) {
    // TODO
    std::cout << "Standstill Triggered" << std::endl;
}