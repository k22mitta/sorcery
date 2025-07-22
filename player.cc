#include "player.h"
#include "minion.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

Player::Player(const std::string &name, int id, std::vector<std::unique_ptr<Card>> &&deck)
    : name{name}, id{id}, deck{std::move(deck)} {}

void Player::drawCard() {
    if (hand.size() < 5 && !deck.empty()) {
        hand.emplace_back(std::move(deck.back()));
        deck.pop_back();
    }
}

void Player::drawInitialHand() {
    for (int i = 0; i < 5; i++) shuffleAndDraw(false, 12345);
}

void Player::playCard(int index, int targetPlayer, int targetCard) {
    if (index < 1 || index > static_cast<int>(hand.size())) {
        std::cout << hand.size() << std::endl;
        std::cerr << "Invalid hand index" << std::endl;
        return;
    }
    auto &currentCard = hand[index - 1];
    if (currentCard->getCost() > magic) {
        std::cout << "No enough magic " << std::endl;
        return;
    }
    changeMagic(-currentCard->getCost());
    switch (currentCard->getType()) {
        case CardType::Minion:
            if (board.size() >= 5) {
                std::cout << "Board full!" << std::endl;
                return;
            }
            std::cout << name << " placed " << currentCard->getName() << std::endl;
            board.emplace_back(std::move(currentCard));
            break;

        case CardType::Spell:
            std::cout << "spell is not allowed to be played on board" << std::endl;
            return;

        case CardType::Ritual:
            ritual = std::move(currentCard);
            break;

        case CardType::Enchantment:
            std::cout << "enchantment is not allowed to be played on board" << std::endl;
            return;
    }
    hand.erase(hand.begin() + (index - 1));
}

void Player::attack(int whoAttack, int whoAttacked, Player &opponent) {
    if (whoAttack < 1 || whoAttack > static_cast<int>(board.size())) {
        std::cout << "Invalid attacker" << std::endl;
        return;
    }
    Card *attackCard = board[whoAttack - 1].get();
    Minion *attacker = dynamic_cast<Minion*>(attackCard);
    if (!attacker->canAct()) {
        std::cout << attacker->getName() << " cannot act" << std::endl;
        return;
    }
    attacker->spendAction();
    if (whoAttacked == -1) {
        std::cout << "attacks opponent directly" << std::endl;
        opponent.changeLife(-attacker->getAttack());
    } else {
        if (whoAttacked < 1 || whoAttacked > static_cast<int>(opponent.board.size())) {
            std::cout << "Invalid target minion index" << std::endl;
            return;
        }
        Card *targetCard = opponent.board[whoAttacked - 1].get();
        Minion *target = dynamic_cast<Minion*>(targetCard);
        if (!target) {
            std::cout << "Target card is not a minion" << std::endl;
            return;
        }
        
        attacker->setDefense(attacker->getDefense() - target->getAttack());
        target->setDefense(target->getDefense() - attacker->getAttack());

        if (attacker->getDefense() <= 0) {
            graveyard.emplace_back(std::move(board[whoAttack - 1]));
            board.erase(board.begin() + (whoAttack - 1));
        }
        if (target->getDefense() <= 0) {
            opponent.graveyard.emplace_back(std::move(opponent.board[whoAttacked - 1]));
            opponent.board.erase(opponent.board.begin() + (whoAttacked - 1));
        }
    }
}

void Player::startTurn() {
    magic++;
    shuffleAndDraw(false, 12345);
    std::cout << name << " starts turn with " << magic << " magic.\n";

    for (auto& card : board) {
        Minion* minion = dynamic_cast<Minion*>(card.get());
        if (minion) {
            minion->restoreAction();
        }
    }
}

void Player::endTurn() {
    std::cout << name << " ends turn.\n";
    // TODO: Trigger end-of-turn effects
}

void Player::shuffleAndDraw(bool testingMode, unsigned seed) {
    if (!testingMode) {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    std::default_random_engine rng{seed};
    std::shuffle(deck.begin(), deck.end(), rng);

    if (!deck.empty() && hand.size() < 5) {
        hand.emplace_back(std::move(deck.back()));
        deck.pop_back();
    }

    for (auto it = deck.begin(); it != deck.end(); ++it) {
        if ((*it)->getType() == CardType::Ritual) {
            ritual = std::move(*it);
            deck.erase(it);
            break;
        }
    }
}

std::string Player::getName() const { return name; }
int Player::getLife() const { return life; }
int Player::getMagic() const { return magic; }
void Player::changeLife(int delta) { life += delta; }
void Player::changeMagic(int delta) { magic += delta; }
std::vector<std::unique_ptr<Card>> &Player::getHand() { return hand; }
std::vector<std::unique_ptr<Card>> &Player::getBoard() { return board; }
std::vector<std::unique_ptr<Card>> &Player::getGraveyard() { return graveyard; }
Card *Player::getRitual() { return ritual.get(); }

void Player::displayHand() const {

}