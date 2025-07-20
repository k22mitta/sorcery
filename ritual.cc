#include "ritual.h"
#include <iostream>
#include <iomanip>

Ritual::Ritual(const std::string &name, const std::string &description, int cost, int activationCost, int charges)
    : Card{name, description, cost}, activationCost{activationCost}, charges{charges} {}

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
