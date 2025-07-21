#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

std::vector<std::string> displayMinion(const std::string &name, int cost, int atk, int def, const std::string &desc = "");
std::vector<std::string> displaySpell(const std::string &name, int cost, const std::string &desc);
std::vector<std::string> displayRitual(const std::string &name, int cost, int charge, const std::string &desc);
std::vector<std::string> displayEnchantment(const std::string &name, int cost, const std::string &desc);

#endif
