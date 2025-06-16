#include "Deck.h"
#include <random>
#include <algorithm>
#include <iostream>

Deck::Deck() {
    initialize();
    shuffle();
}

void Deck::initialize() {
    vector<string> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    vector<char> suits = { 'S', 'H', 'D', 'C' };
    cards.clear();

    for (const auto& rank : ranks)
        for (char suit : suits)
            cards.emplace_back(rank, suit);
}

void Deck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

int Deck::size() const {
    return static_cast<int>(cards.size());
}

Cards Deck::drawCard() {
    if (cards.empty()) {
        cerr << "error, deck is empty!" << endl;
        exit(1);
    }

    Cards top = cards.back();
    cards.pop_back();
    return top;
}
