#include "ability.h"

ActivatedAbility::ActivatedAbility(int cost) : cost{cost} {}

int ActivatedAbility::getCost() const {
    return cost;
}
