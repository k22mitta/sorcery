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

void Board::display(std::ostream &out) {
    Player &current = *players[currentPlayer];
    Player &opponent = *players[1 - currentPlayer];

    std::vector<std::string> topLeft = opponent.getRitual() ? opponent.getRitual()->display() : std::vector<std::string>(7, std::string(33, ' '));
    std::vector<std::string> topCenter = opponent.displayHero();
    std::vector<std::string> topRight = opponent.getGraveyard() ? opponent.getGraveyard()->display() : std::vector<std::string>(7, std::string(33, ' '));
    printCardRow(out, {topLeft, topCenter, topRight});

    std::vector<std::vector<std::string>> topRow;
    for (auto &minion : opponent.getMinions()) {
        topRow.push_back(minion->display());
    }
    printCardRow(out, topRow);

    out << std::string(165, '-') << std::endl;

    std::vector<std::vector<std::string>> bottomRow;
    for (auto &minion : current.getMinions()) {
        bottomRow.push_back(minion->display());
    }
    printCardRow(out, bottomRow);

    std::vector<std::string> bottomLeft = current.getRitual() ? current.getRitual()->display() : std::vector<std::string>(7, std::string(33, ' '));
    std::vector<std::string> bottomCenter = current.displayHero();
    std::vector<std::string> bottomRight = current.getGraveyard() ? current.getGraveyard()->display() : std::vector<std::string>(7, std::string(33, ' '));
    printCardRow(out, {bottomLeft, bottomCenter, bottomRight});

    out << std::endl;
}
