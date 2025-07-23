#include "minion.h"
#include <iostream>
#include <iomanip>

Minion::Minion(const std::string &name, int cost, int atk, int def)
    : Card{name, cost}, atk{atk}, def{def}, actions{0} {}

CardType Minion::getType() const { return CardType::Minion; }

int Minion::getAttack() const { return atk; }
int Minion::getDefense() const { return def; }
void Minion::setAttack(int val) { atk = val; }
void Minion::setDefense(int val) { def = val; }
void Minion::modifyStats(int atkDelta, int defDelta) { atk += atkDelta; def += defDelta; }

bool Minion::canAct() const { return actions > 0; }
void Minion::restoreAction() { actions = 1; }
void Minion::spendAction() { if (actions > 0) --actions; }

Ability* Minion::getAbility() { return ability.get(); }
void Minion::setAbility(std::unique_ptr<Ability> ability) { this -> ability = std::move(ability); }

AirElemental::AirElemental(): Minion{"Air Elemental", 0, 1, 1} {}
EarthElemental::EarthElemental(): Minion{"Earth Elemental", 3, 4, 4} {}
BoneGolem::BoneGolem(): Minion{"Bone Golem", 2, 1, 3} {}
FireElemental::FireElemental(): Minion{"Fire Elemental", 2, 2, 2} {}
PotionSeller::PotionSeller(): Minion{"Potion Seller", 2, 1, 3} {}
NovicePyromancer::NovicePyromancer(): Minion{"Novice Pyromancer", 1, 0, 1} {}
ApprenticeSummoner::ApprenticeSummoner(): Minion{"Apprentice Summoner", 1, 1, 1} {}
MasterSummoner::MasterSummoner(): Minion{"Master Summoner", 3, 2, 3} {}

void AirElemental::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Air Elemental           |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void EarthElemental::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Earth Elemental         |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void BoneGolem::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Bone Golem              |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void FireElemental::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Fire Elemental          |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void PotionSeller::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Potion Seller           |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void NovicePyromancer::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Novice Pyromancer       |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void ApprenticeSummoner::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Apprentice Summoner     |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
void MasterSummoner::display(int line) const {
    switch(line) {
        case 0:
            std::cout << "|-------------------------------|";
            break;
        case 1:
            std::cout << "| Master Summoner         |" << std::setw(5) << cost << "|";
            break;
        case 2:
            std::cout << "|-------------------------------|";
            break;
        case 3: 
            std::cout << "|                        Minion |";
            break;
        case 4:
            std::cout << "|-------------------------------|";
            break;
        case 5:
            std::cout << "|                               |";
            break;
        case 6:
            std::cout << "|                               |";
            break;
        case 7:
            std::cout << "|                               |";
            break;
        case 8:
            std::cout << "|------                   ------|";
            break;
        case 9:
            std::cout << "| " << std::setw(3) << atk << " |                   | " << std::setw(3) << def << " |";
            break;
        case 10:
            std::cout << "|-------------------------------|";
            break;
    }
}
