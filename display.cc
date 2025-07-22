#include "display.h"
#include <sstream>
#include <iomanip>

static const int CARD_WIDTH = 33;

std::vector<std::string> displayMinion(const std::string &name, int cost, int atk, int def, const std::string &desc) {
    std::vector<std::string> card;
    std::ostringstream line;

    line << "| " << std::left << std::setw(27) << name << "|" << std::right << std::setw(3) << cost << " |";
    card.push_back(line.str()); line.str("");
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(12, ' ') + "Minion" + std::string(12, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    std::ostringstream line;
    line << "|" << std::left << std::setw(31) << desc.substr(0, 31) << "|";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    line << "|" << std::setw(3) << atk << " |" << std::setw(25) << "" << std::setw(3) << def << " |";
    card.push_back(line.str());
    return card;
}

std::vector<std::string> displaySpell(const std::string &name, int cost, const std::string &desc) {
    std::vector<std::string> card;
    std::ostringstream line;
    line << "| " << std::left << std::setw(27) << name << "|" << std::right << std::setw(3) << cost << " |";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(13, ' ') + "Spell" + std::string(13, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    std::ostringstream line;
    line << "|" << std::left << std::setw(31) << desc.substr(0, 31) << "|";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    return card;
}

std::vector<std::string> displayRitual(const std::string &name, int cost, int charge, const std::string &desc) {
    std::vector<std::string> card;
    std::ostringstream line;
    line << "| " << std::left << std::setw(27) << name << "|" << std::right << std::setw(3) << cost << " |";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(13, ' ') + "Ritual" + std::string(13, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    std::ostringstream line;
    line << "|" << std::left << std::setw(31) << desc.substr(0, 31) << "|";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    line.str("");
    line << "|" << std::setw(3) << charge << " |" << std::setw(25) << "" << std::setw(3) << " " << " |";
    card.push_back(line.str());
    return card;
}

std::vector<std::string> displayEnchantment(const std::string &name, int cost, const std::string &desc) {
    std::vector<std::string> card;
    std::ostringstream line;
    line << "| " << std::left << std::setw(27) << name << "|" << std::right << std::setw(3) << cost << " |";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(11, ' ') + "Enchantment" + std::string(11, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    std::ostringstream line;
    line << "|" << std::left << std::setw(31) << desc.substr(0, 31) << "|";
    card.push_back(line.str());
    card.push_back("|" + std::string(31, ' ') + "|");
    card.push_back("|" + std::string(31, ' ') + "|");
    return card;
}
