#include "player.h"
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
    for (int i = 0; i < 5; ++i) drawCard();
}

void Player::playCard(int index) {
    if (index < 1 || index > static_cast<int>(hand.size())) return;
    std::cout << name << " plays card " << index << std::endl;
    // TODO: Implement actual card play logic
}

void Player::startTurn() {
    magic++;
    drawCard();
    std::cout << name << " starts turn with " << magic << " magic.\n";
    // TODO: Trigger start-of-turn effects
}

void Player::endTurn() {
    std::cout << name << " ends turn.\n";
    // TODO: Trigger end-of-turn effects
}

void Player::shuffleDeck(bool testingMode, unsigned seed) {
    if (!testingMode) {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    std::default_random_engine rng{seed};
    std::shuffle(deck.begin(), deck.end(), rng);
}

const std::string &Player::getName() const { return name; }
int Player::getLife() const { return life; }
int Player::getMagic() const { return magic; }
void Player::changeLife(int delta) { life += delta; }
void Player::changeMagic(int delta) { magic += delta; }
std::vector<std::unique_ptr<Card>> &Player::getHand() { return hand; }
std::vector<std::unique_ptr<Card>> &Player::getBoard() { return board; }
Card *Player::getRitual() { return ritual.get(); }
Card *Player::getGraveyardTop() { return graveyard.empty() ? nullptr : graveyard.back().get(); }
