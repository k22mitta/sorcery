#include "cardfactory.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"
#include "ability.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::unique_ptr<Card> CardFactory::createCard(const std::string &name) {
    if (name == "Dark Ritual") return std::make_unique<DarkRitual>();
    else if (name == "Aura of Power") return std::make_unique<AuraOfPower>();
    else if (name == "Standstill") return std::make_unique<StandStill>();
    else if (name == "Banish") return std::make_unique<Banish>();
    else if (name == "Unsummon") return std::make_unique<Unsummon>();
    else if (name == "Recharge") return std::make_unique<Recharge>();
    else if (name == "Disenchant") return std::make_unique<Disenchant>();
    else if (name == "RaiseDead") return std::make_unique<RaiseDead>();
    else if (name == "Blizzard") return std::make_unique<Blizzard>();
    else {
        std::cerr << "Unknown card name: " << name << std::endl;
        return nullptr;
    }
}
