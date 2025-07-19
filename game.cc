#include "game.h"
#include "cardfactory.h"
#include <iostream>
#include <fstream>
#include <sstream>

Game::Game(bool testing = false, bool graphics = false)
    : testingMode{testing}, graphicsEnabled{graphics} { }

void Game::init(const std::string &initFile) {
    this->initFile = initFile;
    std::istream *in = &std::cin;
    std::ifstream file;
    if (!initFile.empty()) {
        file.open(initFile);
        if (file) in = &file;
    }

    std::string name1, name2;
    std::getline(*in, name1);
    std::getline(*in, name2);

    auto p1 = std::make_unique<Player>(name1, 1, CardFactory::loadDeck("default.deck"));
    auto p2 = std::make_unique<Player>(name2, 2, CardFactory::loadDeck("default.deck"));
    board = std::make_unique<Board>(std::move(p1), std::move(p2));

    std::string cmd;
    while (std::getline(*in, cmd)) {
        processCommand(cmd);
    }
}

void Game::start() {
    board->getPlayer(1).drawInitialHand();
    board->getPlayer(2).drawInitialHand();
    nextTurn();
}

void Game::nextTurn() {
    currentPlayer = (currentPlayer == 1 ? 2 : 1);
    Player &p = getCurrentPlayer();
    p.startTurn();
    board->display();

    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        if (cmd == "end") break;
        processCommand(cmd);
    }
    p.endTurn();
}

void Game::processCommand(const std::string &cmd) {
    std::cout << "Received command: " << cmd << std::endl;
    // TODO: Implement actual command parsing and dispatch
}

Player &Game::getCurrentPlayer() {
    return board->getPlayer(currentPlayer);
}

Player &Game::getOtherPlayer() {
    return board->getOpponent(currentPlayer);
}

bool Game::isTestingMode() const {
    return testingMode;
}
