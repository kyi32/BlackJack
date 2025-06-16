#include "Player.h"
#include <iostream>

Player::Player(const string& name, int balance)
    : name(name), balance(balance), currentBet(0) {
}

void Player::receiveCard(const Cards& card) {
    hand.addCard(card);
}

void Player::clearHand() {
    hand.clear();
    currentBet = 0;
}

int Player::getScore() const {
    return hand.getScore();
}

bool Player::isBust() const {
    return hand.isBust();
}

void Player::placeBet(int amount) {
    if (amount > balance) amount = balance;
    currentBet += amount;
    balance -= amount;
}

void Player::adjustBalance(int amount) {
    balance += amount;
}

int Player::getBet() const {
    return currentBet;
}

int Player::getBalance() const {
    return balance;
}

string Player::getName() const {
    return name;
}

void Player::printHand() const {
    cout << name << ": ";
    hand.print();
}

Cards Player::getVisibleCard() const {
    return hand.getFirstCard();
}

void Player::addMoney(int amount) {
    if (amount > 0) {
        balance += amount;
        cout << name << " added " << amount << " to balance. Total: " << balance << endl;
    }
    else {
        cout << "Invalid amount.\n";
    }
}
