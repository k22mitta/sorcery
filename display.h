#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

class Board;

class Display {
public:
    virtual ~Display() = default;
    virtual void notify(const Board& board) = 0;
};

#endif
