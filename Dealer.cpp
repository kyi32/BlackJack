#include "Dealer.h"
#include <iostream>

Dealer::Dealer(bool s17) : Player("Dealer", 0), standOnSoft17(s17) {}

bool Dealer::isSoft(const Hand& h) {
    return h.isSoft();
}

void Dealer::makeMove(const Cards&, Deck& deck) {
    std::cout << "Dealer's turn\n";
    while (true) {
        int score = getScore();
        bool soft = isSoft(hand);

        if (score < DEALER_STAND_HARD) {
            draw(deck);
        }
        else if (score == DEALER_STAND_SOFT && soft && !standOnSoft17) {
            draw(deck);
        }
        else {
            break;
        }
    }
    std::cout << "Dealer stands on " << getScore() << '\n';
}

void Dealer::draw(Deck& d) {
    Cards c = d.drawCard();
    receiveCard(c);
    std::cout << "Dealer draws " << c.CardSymbolPlusRank() << '\n';
}
