#ifndef MINION_ABILITIES_H
#define MINION_ABILITIES_H

#include "ability.h"
#include "minion.h"
#include "player.h"
#include "game.h"

class NovicePyromancerAbility : public ActivatedAbility {
public:
    NovicePyromancerAbility() : ActivatedAbility{1} {}
    void execute(Game &game, int targetPlayer, int targetCard) override;
};

class ApprenticeSummonerAbility : public ActivatedAbility {
public:
    ApprenticeSummonerAbility() : ActivatedAbility{1} {}
    void execute(Game &game, int, int) override;       
};

class MasterSummonerAbility : public ActivatedAbility {
public:
    MasterSummonerAbility() : ActivatedAbility{2} {}
    void execute(Game &game, int, int) override;     
};


class BoneGolemTrigger : public TriggeredAbility {
    Minion *host;
public:
    explicit BoneGolemTrigger(Minion *self)
        : TriggeredAbility{"MinionLeaves"}, host{self} {}
    void execute(Game &game, int, int) override;  
};     

class FireElementalTrigger : public TriggeredAbility {
    Minion *host;
public:
    explicit FireElementalTrigger(Minion *self)
        : TriggeredAbility{"MinionEnters"}, host{self} {}
    void execute(Game &game, int targetPlayer, int targetCard) override;
};

class PotionSellerTrigger : public TriggeredAbility {
    Minion *host;
public:
    explicit PotionSellerTrigger(Minion *self)
        : TriggeredAbility{"EndOfTurn"}, host{self} {}
    void execute(Game &game, int, int) override;
};

#endif
