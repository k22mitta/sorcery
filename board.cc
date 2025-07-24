#include "board.h"
#include "ritual.h"
#include <iostream>

Board::Board(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2)
    : player1{std::move(p1)}, player2{std::move(p2)} {}

Player &Board::getPlayer(int id) {
    return (id == 1) ? *player1 : *player2;
}

Player &Board::getOpponent(int id) {
    return (id == 1) ? *player2 : *player1;
}

void Board::printRow(const std::vector<card_template_t>& cards, int height) const {
    for (int line = 0; line < height; line++) {
        for (const auto& card : cards) {
            std::cout << card[line];
        }
        std::cout << std::endl;
    }
}

void Board::display() const {
    const int BOARD_LIMIT = 5;

    std::vector<card_template_t> p1Minions;
    std::vector<card_template_t> p2Minions;

    Player& p1 = *player1;
    Player& p2 = *player2;

    auto &p1Board = player1->getBoard();
    auto &p2Board = player2->getBoard();

    card_template_t p1ritual = p1.getRitual() ? p1.getRitual()->display() : CARD_TEMPLATE_BORDER;
    card_template_t p1graveyard = !p1.getGraveyard().empty() ? p1.getGraveyard().back()->display() : CARD_TEMPLATE_BORDER;

    card_template_t p2ritual = p2.getRitual() ? p2.getRitual()->display() : CARD_TEMPLATE_BORDER;
    card_template_t p2graveyard = !p2.getGraveyard().empty() ? p2.getGraveyard().back()->display() : CARD_TEMPLATE_BORDER;

    card_template_t p1Info = display_player_card(1, p1.getName(), p1.getLife(), p1.getMagic());
    card_template_t p2Info = display_player_card(2, p2.getName(), p2.getLife(), p2.getMagic());

    for (const auto &minion : p1Board) {
        p1Minions.emplace_back(minion->display());
    }
    while (p1Minions.size() < BOARD_LIMIT) {
        p1Minions.push_back(CARD_TEMPLATE_BORDER);
    }
    for (const auto &minion : p2Board) {
        p2Minions.emplace_back(minion->display());
    }
    while (p2Minions.size() < BOARD_LIMIT) {
        p2Minions.push_back(CARD_TEMPLATE_BORDER);
    }

    printRow(p1Minions, BLOCK_HEIGHT);
    printRow({p1ritual, CARD_TEMPLATE_EMPTY, p1Info, CARD_TEMPLATE_EMPTY, p1graveyard}, BLOCK_HEIGHT);
    printRow({CENTRE_GRAPHIC}, 10);
    printRow({p2ritual, CARD_TEMPLATE_EMPTY, p2Info, CARD_TEMPLATE_EMPTY, p2graveyard}, BLOCK_HEIGHT);
    printRow(p2Minions, BLOCK_HEIGHT);
}

void Board::displayHand(Player& player) const {
    std::vector<card_template_t> handGraphics;

    for (const auto& card : player.getHand()) {
        handGraphics.push_back(card->display());
    }

    if (handGraphics.empty()) {
        std::cout << "Hand is empty." << std::endl;
        return;
    }

    printRow(handGraphics, BLOCK_HEIGHT);
}