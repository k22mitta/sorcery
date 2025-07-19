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
        deck.emplace_back(createCard(name));
    }
    return deck;
}

std::unique_ptr<Card> CardFactory::createCard(const std::string &name) {
    if (name == "Novice Pyromancer") {
        return std::make_unique<Minion>("Novice Pyromancer", 1, 0, 1);
    } else if (name == "Air Elemental") {
        return std::make_unique<Minion>("Air Elemental", 0, 1, 1);
    } else if (name == "Blizzard") {
        class Blizzard : public Spell {
        public:
            Blizzard() : Spell("Blizzard", 3) {}
            void effect(Game &game, int, int) override {
                std::cout << "Blizzard deals 2 damage to all minions.\n";
                // TODO: Apply effect to board
            }
        };
        return std::make_unique<Blizzard>();
    } else if (name == "Giant Strength") {
        class GiantStrength : public Enchantment {
        public:
            GiantStrength(std::unique_ptr<Card> target)
                : Enchantment("Giant Strength", 1, std::move(target)) {
                setStatModifier(2, 2);
            }
        };
        // Return a placeholder target for now
        return std::make_unique<GiantStrength>(std::make_unique<Minion>("Dummy", 0, 1, 1));
    } else if (name == "Dark Ritual") {
        return std::make_unique<Ritual>("Dark Ritual", 0, 1, 5);
    }

    std::cerr << "Unknown card name: " << name << std::endl;
    return nullptr;
}
