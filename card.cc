#include "card.h"

Card::Card(const std::string &name, const std::string &description, int cost) : name{name}, description{description}, cost{cost} {}

std::string Card::getName() const { return name; }
std::string Card::getDescription() const { return description; }
int Card::getCost() const { return cost; }
