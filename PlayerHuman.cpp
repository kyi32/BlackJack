#include "PlayerHuman.h"
#include <iostream>

PlayerHuman::PlayerHuman(const string& name, int balance) : Player(name, balance) {}

void PlayerHuman::makeMove(const Cards& dealerCard, Deck& deck) {
    string action;
    bool firstMove = true;

    while (true) {
        printHand();
        cout << "Dealer's open card: " << dealerCard.CardSymbolPlusRank() << endl;

        if (isBust()) {
            cout << "You busted!" << endl;
            break;
        }

        cout << "(hit / stand";
        if (firstMove && getBalance() >= getBet()) cout << " / double";
        cout << "): ";
        cin >> action;

        if (action == "hit") {
            Cards newCard = deck.drawCard();
            cout << "You got: " << newCard.CardSymbolPlusRank() << endl;
            receiveCard(newCard);
        }
        else if (action == "stand") {
            break;
        }
        else if (action == "double" && firstMove && getBalance() >= getBet()) {
            placeBet(getBet());
            cout << "You doubled your bet to " << getBet() << endl;
            Cards newCard = deck.drawCard();
            cout << "You got: " << newCard.CardSymbolPlusRank() << endl;
            receiveCard(newCard);
            break;
        }
        else {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        firstMove = false;
    }
}
