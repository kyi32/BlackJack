#include "System.h"
#include <iostream>

System::System() : player1("Ryba", 100), player2("Kyi", 100), dealer() {}

void System::start() {
    cout << "Welcome to Blackjack!\n";

    while (true) {
        if (player1.getBalance() <= 0 && player2.getBalance() <= 0) {
            cout << "Both players are out of money. Game over.\n";
            break;
        }

        playRound();

        char again;
        cout << "Play again? (y/n): ";
        cin >> again;
        if (again != 'y') break;
    }
}

void System::handleTopUp(PlayerHuman& player) {
    char choice;
    cout << player.getName() << " balance: " << player.getBalance() << ". Add money? (y/n): ";
    cin >> choice;
    if (choice == 'y') {
        int amount;
        cout << "Enter amount to add: ";
        cin >> amount;
        player.addMoney(amount);
    }
}

void System::playRound() {
    deck.initialize();
    deck.shuffle();
    player1.clearHand();
    player2.clearHand();
    dealer.clearHand();

    cout << "\n--- New Round ---\n";
    handleTopUp(player1);
    handleTopUp(player2);

    int bet1, bet2;
    cout << player1.getName() << ", enter your bet: ";
    cin >> bet1;
    player1.placeBet(bet1);

    cout << player2.getName() << ", enter your bet: ";
    cin >> bet2;
    player2.placeBet(bet2);

    player1.receiveCard(deck.drawCard());
    player2.receiveCard(deck.drawCard());
    dealer.receiveCard(deck.drawCard());
    player1.receiveCard(deck.drawCard());
    player2.receiveCard(deck.drawCard());
    dealer.receiveCard(deck.drawCard());

    player1.makeMove(dealer.getVisibleCard(), deck);
    player2.makeMove(dealer.getVisibleCard(), deck);
    dealer.makeMove(dealer.getVisibleCard(), deck);

    displayResults(player1);
    displayResults(player2);
}

void System::displayResults(PlayerHuman& player) {
    cout << "\nResult for " << player.getName() << ":\n";
    player.printHand();
    dealer.printHand();

    int playerScore = player.getScore();
    int dealerScore = dealer.getScore();

    if (player.isBust()) {
        cout << player.getName() << " busted.\n";
    }
    else if (dealer.isBust() || playerScore > dealerScore) {
        cout << player.getName() << " wins!\n";
        player.adjustBalance(player.getBet() * 2);
    }
    else if (playerScore == dealerScore) {
        cout << player.getName() << " draws.\n";
        player.adjustBalance(player.getBet());
    }
    else {
        cout << player.getName() << " loses.\n";
    }

    cout << player.getName() << " balance: " << player.getBalance() << "\n";
}
