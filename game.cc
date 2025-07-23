#include "game.h"
#include "cardfactory.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Game::helpMsg() const {
    std::cout << "Commands: help -- Display this message." << std::endl;
    std::cout << "          end  -- End the current player's turn." << std::endl;
    std::cout << "          quit -- End the game." << std::endl;
    std::cout << "          attack minion other-minion -- Orders minion to attack other-minion." << std::endl;
    std::cout << "          attack minion -- Orders minion to attack the opponent." << std::endl;
    std::cout << "          play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player." << std::endl;
    std::cout << "          use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player." << std::endl;
    std::cout << "          inspect minion -- View a minion's card and all enchantments on that minion." << std::endl;
    std::cout << "          hand -- Describe all cards in your hand." << std::endl;
    std::cout << "          board -- Describe all cards on the board." << std::endl;
}

Game::Game(bool testing, bool graphics, std::string deckFile1, std::string deckFile2)
    : testingMode{testing}, graphicsEnabled{graphics}, deckFile1{deckFile1}, deckFile2{deckFile2} { }

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

    auto p1 = std::make_unique<Player>(name1, 1, CardFactory::loadDeck(deckFile1));
    auto p2 = std::make_unique<Player>(name2, 2, CardFactory::loadDeck(deckFile2));

    p1->drawInitialHand();
    p2->drawInitialHand();

    board = std::make_unique<Board>(std::move(p1), std::move(p2));

}

void Game::start() {
    while (true) {
        Player &p = getCurrentPlayer();
        p.startTurn();
        board->start_turn(currentPlayer,*this);
        std::string cmd;
        while (std::getline(std::cin, cmd)) {
            if (cmd == "end") break;
            processCommand(cmd);
        }
        board->end_turn(currentPlayer,*this);
        p.endTurn();
        togglePlayer();
    }
}

void Game::processCommand(const std::string &line) {
    Player& currentPlayer = getCurrentPlayer();
    std::istringstream iss{line};
    std::string cmd;
    iss >> cmd;

    if (cmd == "help") {
        helpMsg();
    } else if (cmd == "end") {

    } else if (cmd == "quit") {
        std::exit(EXIT_SUCCESS);
    } else if (cmd == "attack") {
        int i, j = -1;
        if (iss >> i) {
            if (!(iss >> j)) {
                j = -1;
            }
            currentPlayer.attack(i, j, getOtherPlayer());
            board->minion_leave(currentPlayer,*this);
            board->minion_leave((currentPlayer == 1 ? 2 : 1),*this);
        }
    } else if (cmd == "play") {
        int i, p = -1, t = -1;
        if (iss >> i) {
            if (iss >> p) {
                if (!(iss >> t)) {
                    t = -1;
                }
            }
            currentPlayer.playCard(i, p, t);
            board->minion_enter(currentPlayer,*this);
        }
    } else if (cmd == "inspect") {

    } else if (cmd == "hand") {
        currentPlayer.displayHand();
    } else if (cmd == "board") {
        board -> display();
    } else {
        std::cerr << "Unknown command." << std::endl;
    }
}

Player &Game::getCurrentPlayer() {
    return board->getPlayer(currentPlayer);
}

Player &Game::getOtherPlayer() {
    return board->getOpponent(currentPlayer);
}

void Game::togglePlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

bool Game::isTestingMode() const {
    return testingMode;
}
