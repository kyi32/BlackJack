#pragma once
#include "Player.h"

class PlayerHuman : public Player {
public:
    PlayerHuman(const string& name, int balance);
    void makeMove(const Cards& dealerCard, Deck& deck) override;
};
