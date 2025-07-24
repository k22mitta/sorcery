#include "spell.h"
#include "game.h"
#include "ritual.h"
#include <iostream>
#include <iomanip>

Spell::Spell(const std::string &name, int cost) : Card{name, cost} {}

CardType Spell::getType() const { return CardType::Spell; }

Banish::Banish(): Spell{"Banish", 2} {}
Unsummon::Unsummon(): Spell{"Unsummon", 1}{}
Recharge::Recharge(): Spell{"Recharge", 1} {}
Disenchant::Disenchant(): Spell{"Disenchant", 1} {}
RaiseDead::RaiseDead(): Spell{"Raise Dead", 1} {}
Blizzard::Blizzard(): Spell{"Blizzard", 3} {}

void Banish::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Banish                   |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Destroy target minion or      |"; break;
        case 6:  std::cout << "| ritual                        |"; break;
        case 7:  std::cout << "|                               |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}

void Unsummon::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Unsummon                |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Return target minion to its   |"; break;
        case 6:  std::cout << "| owner's hand                  |"; break;
        case 7:  std::cout << "|                               |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}

void Recharge::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Recharge                |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Your ritual gains 3 charges   |"; break;
        case 6:  std::cout << "|                               |"; break;
        case 7:  std::cout << "|                               |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}

void Disenchant::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Disenchant              |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Destroy the top enchantment   |"; break;
        case 6:  std::cout << "| on target minion              |"; break;
        case 7:  std::cout << "|                               |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}

void RaiseDead::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Raise Dead              |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Resurrect the top minion in   |"; break;
        case 6:  std::cout << "| your graveyard and set its.   |"; break;
        case 7:  std::cout << "| defence to 1                  |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}

void Blizzard::display(int line) const {
    switch (line) {
        case 0:  std::cout << "|-------------------------------|"; break;
        case 1:  std::cout << "| Blizzard                |" << std::setw(5) << cost << "|"; break;
        case 2:  std::cout << "|-------------------------------|"; break;
        case 3:  std::cout << "|                         Spell |"; break;
        case 4:  std::cout << "|-------------------------------|"; break;
        case 5:  std::cout << "| Deal 2 damage to all minions  |"; break;
        case 6:  std::cout << "|                               |"; break;
        case 7:  std::cout << "|                               |"; break;
        case 8:  std::cout << "|                               |"; break;
        case 9:  std::cout << "|                               |"; break;
        case 10: std::cout << "|-------------------------------|"; break;
    }
}


void Banish::effect(Game *game, int targetPlayer, int targetCard) {
    targetCard--;
    auto &p = game->getPlayer(targetPlayer);
    if (targetCard == 6) {
        p.removeRitual();
    } else {
        p.destroyMinion(targetCard);
    }
}
void Unsummon::effect(Game *game, int targetPlayer, int targetIndex) {
    auto &player = game -> getPlayer(targetPlayer);
    auto &board = player.getBoard();
    auto &hand = player.getHand();
    if (targetIndex < 1 || targetIndex > board.size() || hand.size() >= 5) return;

    std::unique_ptr<Card> card = std::move(board[targetIndex - 1]);
    board.erase(board.begin() + (targetIndex - 1));
    hand.emplace_back(std::move(card));
}
void Recharge::effect(Game *game, int targetPlayer, int targetCard) {
    auto ritual = game->getPlayer(targetPlayer).getRitual();
    if (ritual) {
        ritual->addCharges(3);
    }
}
void Disenchant::effect(Game *game, int targetPlayer, int targetCard) {
    // TODO
}
void RaiseDead::effect(Game *game, int targetPlayer, int targetCard) {
    auto &player = game -> getPlayer(targetPlayer);
    auto &graveyard = player.getGraveyard();
    auto &board = player.getBoard();
    if (graveyard.empty() || board.size() >= 5) return;
    std::unique_ptr<Card> card = std::move(graveyard.back());
    graveyard.pop_back();
    Minion *minion = dynamic_cast<Minion*>(card.get());
    minion->setDefense(1);
    board.emplace_back(std::move(card));
}
void Blizzard::effect(Game *game, int targetPlayer, int targetCard) {
    for (int p = 0; p < 2; p++) {
        auto &player = game -> getPlayer(p);
        for (size_t i = 0; i < player.getBoard().size(); i++) {
            Card *card = player.getBoard()[i].get();
            Minion *minion = dynamic_cast<Minion*>(card);
            minion -> setDefense(minion->getDefense() - 2);
            if (minion->getDefense() <= 0) {
                player.destroyMinion(i);
                i--;
            }
        }
    }
}