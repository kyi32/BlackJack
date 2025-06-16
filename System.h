#pragma once
#include "Deck.h"
#include "PlayerHuman.h"
#include "Dealer.h"

class System {
private:
    Deck deck;
    PlayerHuman player1;
    PlayerHuman player2;
    Dealer dealer;

public:
    System();
    void start();
    void playRound();
    void displayResults(PlayerHuman& player);
    void handleTopUp(PlayerHuman& player);
};
