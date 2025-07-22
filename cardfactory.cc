#include "cardfactory.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::unique_ptr<Card>> CardFactory::loadDeck(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::unique_ptr<Card>> deck;
    std::string name;
    while (std::getline(file, name)) {
        auto card = createCard(name);
        if (card) deck.emplace_back(std::move(card));
    }
    return deck;
}

std::unique_ptr<Card> CardFactory::createCard(const std::string &name) {
    if (name == "Air Elemental") return std::make_unique<Minion>("Air Elemental", 0, 1, 1);
    else if (name == "Earth Elemental") return std::make_unique<Minion>("Earth Elemental", 3, 4, 4);
    else if (name == "Bone Golem") return std::make_unique<Minion>("Bone Golem", 2, 1, 3);
    else if (name == "Fire Elemental") return std::make_unique<Minion>("Fire Elemental", 2, 2, 2);
    else if (name == "Potion Seller") return std::make_unique<Minion>("Potion Seller", 2, 1, 3);
    else if (name == "Novice Pyromancer") return std::make_unique<Minion>("Novice Pyromancer", 1, 0, 1);
    else if (name == "Apprentice Summoner") return std::make_unique<Minion>("Apprentice Summoner", 1, 1, 1);
    else if (name == "Master Summoner") return std::make_unique<Minion>("Master Summoner", 3, 2, 3);
    else if (name == "Dark Ritual") return std::make_unique<DarkRitual>();
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
