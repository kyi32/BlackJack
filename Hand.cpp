#include "Hand.h"
#include <iostream>
#include <stdexcept>

void Hand::addCard(const Cards& card) {
    cards.push_back(card);
}

void Hand::clear() {
    cards.clear();
}

bool Hand::isSoft() const {
    if (getScore() > 21) return false;
    for (const auto& c : cards)
        if (c.GetRankCard() == "A") return true;
    return false;
}

int Hand::getScore() const {
    int score = 0, aceCount = 0;
    for (const auto& card : cards) {
        score += card.GetValueFormCard();
        if (card.GetRankCard() == "A") aceCount++;
    }

    while (score > 21 && aceCount > 0) {
        score -= 10;
        aceCount--;
    }

    return score;
}

bool Hand::isBust() const {
    return getScore() > 21;
}

void Hand::print() const {
    for (const auto& card : cards)
        cout << card.CardSymbolPlusRank() << " ";
    cout << "(score: " << getScore() << ")" << endl;
}

int Hand::size() const {
    return static_cast<int>(cards.size());
}

Cards Hand::getFirstCard() const {
    if (!cards.empty()) return cards[0];
    throw runtime_error("Hand is empty");
}
