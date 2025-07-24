#ifndef MINION_H
#define MINION_H

#include "ability.h"
#include "card.h"
#include "ascii_graphics.h"
#include <memory>


class Minion : public Card {
protected:
    int atk;
    int def;
    int actions;
    std::unique_ptr<Ability> ability;

public:
    Minion(const std::string &name, int cost, std::string description, int atk, int def);

    CardType getType() const override;

    int getAttack() const;
    int getDefense() const;
    void setAttack(int val);
    void setDefense(int val);
    void modifyStats(int atkDelta, int defDelta);

    bool canAct() const;
    void restoreAction();
    void spendAction();

    virtual Ability *getAbility();
    void setAbility(std::unique_ptr<Ability> ability);

    card_template_t display() const override;
};

class AirElemental : public Minion {
public:
    AirElemental();
};

class EarthElemental : public Minion {
public:
    EarthElemental();
};

class BoneGolem : public Minion {
public:
    BoneGolem();
};

class FireElemental : public Minion {
public:
    FireElemental();
};

class PotionSeller : public Minion {
public:
    PotionSeller();
};

class NovicePyromancer : public Minion {
public:
    NovicePyromancer();
};

class ApprenticeSummoner : public Minion {
public:
    ApprenticeSummoner();
};

class MasterSummoner : public Minion {
public:
    MasterSummoner();
};

#endif
