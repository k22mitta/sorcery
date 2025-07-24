#include "card.h"

Card::Card(const std::string &name, int cost, std::string description) : name{name}, cost{cost}, description{description} {}

std::string Card::getName() const { return name; }
int Card::getCost() const { return cost; }
