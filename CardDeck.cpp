#include "CardDeck.h"

CardDeck::CardDeck(int decks)
{
    for(int i = 0; i < decks; i++)
    {
        add_one_deck();
    }

    //random_shuffle(deck.begin(), deck.end());
}

//判断牌堆是否为空
bool CardDeck::empty_deck()
{
    return deck.empty();
}

//从别的牌堆得到一张牌
void CardDeck::get_one_card(Card cd)
{
    deck.push_back(cd);
}

//给一张牌到别的牌堆
void CardDeck::give_one_card(CardDeck &to, Card cd)
{
    vector<Card>::iterator it = find(deck.begin(), deck.end(), cd);
    if(it != deck.end())
    {
        to.get_one_card(cd);
        deck.erase(it);
    }
}

//往牌堆中加一副牌
void CardDeck::add_one_deck()
{
    Card red_joker(joker, red);
    Card black_joker(joker, black);

    deck.push_back(red_joker);
    deck.push_back(black_joker);

    for(int i = ace; i <= king;  i++)
    {
        for(int j = heart; j <= diamond; j++)
        {
            Card tmp_card(Card::card_point_cast(i), Card::card_color_cast(j));
            deck.push_back(tmp_card);
        }
    }
}

void CardDeck::print_cards()
{
    for(unsigned int i = 0; i < deck.size(); i++)
    {
        qDebug()<<deck[i].get_color_str() + " " + deck[i].get_point_str();
    }
    qDebug()<<deck.size()<<" total";
}
