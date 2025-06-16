#include "Cards.h"

Cards::Cards(string rankCard, char symbol) : RankCard(rankCard), Symbol(symbol) {}

int Cards::GetValueFormCard() const {
    if (RankCard == "A") return 11;
    if (RankCard == "K" || RankCard == "Q" || RankCard == "J") return 10;
    return stoi(RankCard);
}

string Cards::CardSymbolPlusRank() const {
    return RankCard + Symbol;
}

string Cards::GetRankCard() const {
    return RankCard;
}

char Cards::GetSymbol() const {
    return Symbol;
}