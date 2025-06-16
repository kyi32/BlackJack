#pragma once
#include <string>
#include "Hand.h"
#include "Deck.h"
using namespace std;

class Player {
protected:
    string name;
    int balance;
    int currentBet;
    Hand hand;

public:
    Player(const string& name, int balance);
    virtual ~Player() = default;

    virtual void makeMove(const Cards& dealerCard, Deck& deck) = 0;
    void receiveCard(const Cards& card);
    void clearHand();
    int getScore() const;
    bool isBust() const;
    void placeBet(int amount);
    void adjustBalance(int amount);
    int getBet() const;
    int getBalance() const;
    string getName() const;
    void printHand() const;
    Cards getVisibleCard() const;
    void addMoney(int amount);
};
