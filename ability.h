#ifndef ABILITY_H
#define ABILITY_H

class Game;

class Ability {
public:
    virtual void execute(Game &game, int targetPlayer = -1, int targetCard = -1) = 0;
    virtual ~Ability() = default;
};

class ActivatedAbility : public Ability {
    int cost;

public:
    ActivatedAbility(int cost);
    int getCost() const;
};
hhh
#endif
