#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <string>
#include <vector>
#include <memory>
#include "card.h"

class CardFactory {
public:
    static std::vector<std::unique_ptr<Card>> loadDeck(const std::string &filename);
    static std::unique_ptr<Card> createCard(const std::string &name);
};

#endif
