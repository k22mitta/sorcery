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

void Board::displayEmptyBlock(int line) const {
    if (line == 0 || line == BLOCK_HEIGHT - 1) std::cout << "|-------------------------------|";
    else std::cout << "|                               |";
}

void Board::display() const {
    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        std::cout << '|';
        // displayEmptyBlock(i);
        player1->getRitual() ? player1->getRitual()->display(i) : displayEmptyBlock(i);
        std::cout << "                                 ";
        player1->display(i, 1);
        std::cout << "                                 ";
        player1->getGraveyard().size() == 0 ? displayEmptyBlock(i) : player1->getGraveyard().front()->display(i);
        std::cout << '|' << std::endl;
    }
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        std::cout << '|';
        for (int j = 0; j < 5; j++) {
            j < player1->getBoard().size() ? player1->getBoard()[j]->display(i) : displayEmptyBlock(i);
        }
        std::cout << '|' << std::endl;
    }
    std::cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|                                                                 _____                                                                                               |" << std::endl;
    std::cout << "|                                                                / ____|                                                                                              |" << std::endl;
    std::cout << "|                                                               | (___   ___  _ __ ___ ___ _ __ _   _                                                                 |" << std::endl;
    std::cout << "|                                                                \\___ \\ / _ \\| '__/ __/ _ \\ '__| | | |                                                                |" << std::endl;
    std::cout << "|                                                                ____) | (_) | | | (_|  __/ |  | |_| |                                                                |" << std::endl;
    std::cout << "|                                                               |_____/ \\___/|_|  \\___\\___|_|   \\__, |                                                                |" << std::endl;
    std::cout << "|                                                                                                __/ |                                                                |" << std::endl;
    std::cout << "|                                                                                               |___/                                                                 |" << std::endl;
    std::cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        std::cout << '|';
        for (int j = 0; j < 5; j++) {
            j < player2->getBoard().size() ? player2->getBoard()[j]->display(i) : displayEmptyBlock(i);
        }
        std::cout << '|' << std::endl;
    }
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        std::cout << '|';
        // displayEmptyBlock(i);
        player2->getRitual() ? player2->getRitual()->display(i) : displayEmptyBlock(i);
        std::cout << "                                 ";
        player2->display(i, 2);
        std::cout << "                                 ";
        player2->getGraveyard().size() == 0 ? displayEmptyBlock(i) : player2->getGraveyard().front()->display(i);
        std::cout << '|' << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}
