#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "player.h"

#define BLOCK_HEIGHT 11

class Board {
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    void print(const std::vector<card_template_t> &cards, int height) const;

public:
    Board(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2);

    Player &getPlayer(int id);
    Player &getOpponent(int id);
    void display() const;
    void displayHand(Player& player) const;
};

#endif
