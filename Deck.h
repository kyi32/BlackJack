#pragma once
#include <vector>
#include "Cards.h"
using namespace std;

class Deck {
private:
    vector<Cards> cards;

public:
    Deck();
    void initialize();
    void shuffle();
    int size() const;
    Cards drawCard();
};