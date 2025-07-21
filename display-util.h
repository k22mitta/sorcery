#ifndef DISPLAY_UTIL_H
#define DISPLAY_UTIL_H

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> combineCardRows(const std::vector<std::vector<std::string>> &cardRows);
void printCardRow(std::ostream &out, const std::vector<std::vector<std::string>> &cardRows);

#endif
