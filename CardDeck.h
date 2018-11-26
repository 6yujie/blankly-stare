#ifndef CARDDECK_H
#define CARDDECK_H

#include "mainwindow.h"
#include "Card.h"

class CardDeck
{
public:
    CardDeck(int decks = 1);

    //判断是否是空牌堆
    bool empty_deck();

    //返回牌堆中牌的数量
    int size();

    //确认牌堆里有n张某点数的牌，不考虑花色
    bool find(Card cd, int n = 1);

    vector<Card> data()
    {
        return deck;
    }

    //从别的牌堆得到一张牌
    void get_one_card(Card cd);

    //给别的牌堆一张选定的牌
    void give_selected_card(CardDeck &to, Card cd);

    //把自己的第一张牌给别的牌堆
    void give_one_card(CardDeck &to);

    //判断是否包含一组牌
    bool contains(vector<Card> sub);

    void print_cards();
    void sort_cards();

private:
    vector<Card> deck;

    void add_one_deck();
};

#endif // CARDDECK_H
