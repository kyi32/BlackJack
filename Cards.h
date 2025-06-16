#pragma once
#include <string>
using namespace std;

class Cards {
private:
    string RankCard;
    char Symbol;

public:
    Cards(string rankCard, char symbol);
    int GetValueFormCard() const;
    string CardSymbolPlusRank() const;
    string GetRankCard() const;
    char GetSymbol() const;
};