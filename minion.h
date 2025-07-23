#ifndef MINION_H
#define MINION_H

#include "ability.h"
#include "card.h"

class Minion : public Card {
protected:
    int atk;
    int def;
    int actions;
    std::unique_ptr<Ability> ability;

public:
    Minion(const std::string &name, int cost, int atk, int def);

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
};

class AirElemental : public Minion {
public:
    AirElemental();
    void display(int line) const override;
};

class EarthElemental : public Minion {
public:
    EarthElemental();
    void display(int line) const override;
};

class BoneGolem : public Minion {
public:
    BoneGolem();
    void display(int line) const override;
};

class FireElemental : public Minion {
public:
    FireElemental();
    void display(int line) const override;
};

class PotionSeller : public Minion {
public:
    PotionSeller();
    void display(int line) const override;
};

class NovicePyromancer : public Minion {
public:
    NovicePyromancer();
    void display(int line) const override;
};

class ApprenticeSummoner : public Minion {
public:
    ApprenticeSummoner();
    void display(int line) const override;
};

class MasterSummoner : public Minion {
public:
    MasterSummoner();
    void display(int line) const override;
};

#endif
