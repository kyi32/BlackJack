#pragma once
#include "Player.h"

constexpr int DEALER_STAND_HARD = 17;
constexpr int DEALER_STAND_SOFT = 17;

class Dealer : public Player {
    bool standOnSoft17;

public:
    Dealer(bool s17 = true);
    void makeMove(const Cards&, Deck& deck) override;
    static bool isSoft(const Hand& h);

private:
    void draw(Deck& d);
};
