#pragma once
#include <vector>
#include "Cards.h"
using namespace std;

class Hand {
private:
    vector<Cards> cards;

public:
    void addCard(const Cards& card);
    void clear();
    int getScore() const;
    bool isBust() const;
    bool isSoft() const;
    void print() const;
    int size() const;
    Cards getFirstCard() const;
};