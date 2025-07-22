#include "display_util.h"
#include <algorithm>

std::vector<std::string> combineCardRows(const std::vector<std::vector<std::string>> &cardRows) {
    size_t rowHeight = 0;
    for (const auto &card : cardRows) {
        rowHeight = std::max(rowHeight, card.size());
    }

    std::vector<std::string> result(rowHeight);
    for (size_t line = 0; line < rowHeight; ++line) {
        for (const auto &card : cardRows) {
            if (line < card.size()) {
                result[line] += card[line];
            } else {
                result[line] += std::string(card[0].size(), ' ');
            }
        }
    }
    return result;
}

void printCardRow(std::ostream &out, const std::vector<std::vector<std::string>> &cardRows) {
    auto combined = combineCardRows(cardRows);
    for (const auto &line : combined) {
        out << line << '\n';
    }
}
