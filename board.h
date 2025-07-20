#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "player.h"
#include "display.h"

class Board {
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    std::vector<Display*> observers;

public:
    Board(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2);

    Player &getPlayer(int id);
    Player &getOpponent(int id);
    void attach(Display* observer);
    void notifyObservers() const;
    void display() const;
};

#endif
