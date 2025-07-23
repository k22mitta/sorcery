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

    void start_turn(int player_id, Game &game);
    void end_turn(int player_id, Game &game);
    void minion_enter(int player_id, Game &game);
    void minion_leave(int player_id, Game &game);
};

#endif
