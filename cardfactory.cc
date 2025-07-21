#include "cardfactory.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"
#include "ability.h"
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
        auto minion = std::make_unique<Minion>("Novice Pyromancer", 1, 0, 1);
        class Deal1Damage : public ActivatedAbility {
        public:
            Deal1Damage() : ActivatedAbility(1) {}
            void execute(Game &game, int targetPlayer, int targetCard) override {
                std::cout << "Novice Pyromancer deals 1 damage to target minion.\n";
                // TODO: Implement damage logic
            }
        };
        minion->setAbility(std::make_unique<Deal1Damage>());
        return minion;
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
            GiantStrength(std::unique_ptr<Minion> target)
                : Enchantment("Giant Strength", 1, std::move(target)) {
                setStatModifier(2, 2);
            }
        };
        return std::make_unique<GiantStrength>(std::make_unique<Minion>("Placeholder", 0, 1, 1));
    } else if (name == "Magic Fatigue") {
        class MagicFatigue : public Enchantment {
        public:
            MagicFatigue(std::unique_ptr<Minion> target)
                : Enchantment("Magic Fatigue", 0, std::move(target)) {
                // Future extension: increase ability cost, suppress
            }
        };
        return std::make_unique<MagicFatigue>(std::make_unique<Minion>("Placeholder", 0, 1, 1));
    } else if (name == "Dark Ritual") {
        return std::make_unique<Ritual>("Dark Ritual", 0, 1, 5);
    }

    std::cerr << "Unknown card name: " << name << std::endl;
    return nullptr;
}
