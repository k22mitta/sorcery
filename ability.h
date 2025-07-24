#ifndef ABILITY_H
#define ABILITY_H

#include<string>
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

class TriggeredAbility : public Ability {
    std::string triggerKey;
public:
    explicit TriggeredAbility(std::string key) : triggerKey{std::move(key)} {}
    const std::string &key() const { return triggerKey; }
};
#endif


#endif
