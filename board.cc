#include "board.h"
#include <iostream>

Board::Board(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2)
    : player1{std::move(p1)}, player2{std::move(p2)} {}

Player &Board::getPlayer(int id) {
    return (id == 1) ? *player1 : *player2;
}

Player &Board::getOpponent(int id) {
    return (id == 1) ? *player2 : *player1;
}

void Board::attach(Display* observer) {
        observers.emplace_back(observer);
}

void Board::notifyObservers() const {
    for (auto* obs : observers) {
        obs->notify(*this);
    }
}

void Board::display() const {
    // Placeholder for now
    std::cout << "Displaying board state...\n";
    std::cout << player1->getName() << " (Life: " << player1->getLife()
              << ", Magic: " << player1->getMagic() << ")\n";
    std::cout << player2->getName() << " (Life: " << player2->getLife()
              << ", Magic: " << player2->getMagic() << ")\n";
}
