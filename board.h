#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "player.h"

#define BLOCK_HEIGHT 11

class Board {
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

public:
    Board(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2);

    Player &getPlayer(int id);
    Player &getOpponent(int id);
    void displayEmptyBlock(int line) const;
    void display() const;

    void start_turn(int playerId);
    void end_turn(int playerId);
    void minion_enter(int playerId);
    void minion_leave(int playerId, int index);
};

#endif
