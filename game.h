#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <string>
#include "player.h"
#include "board.h"

class Game {
    std::unique_ptr<Board> board;
    int currentPlayer = 1;
    bool testingMode = false;
    bool graphicsEnabled = false;
    std::string initFile;

public:
    Game(bool testing = false, bool graphics = false);
    void init(const std::string &initFile = "");
    void start();
    void nextTurn();
    void processCommand(const std::string &cmd);
    Player &getCurrentPlayer();
    Player &getOtherPlayer();
    bool isTestingMode() const;
};

#endif
