#ifndef CARDDECK_H
#define CARDDECK_H

#include "mainwindow.h"
#include "Card.h"

class CardDeck
{
public:
    CardDeck(int decks = 1);
    bool empty_deck();
    void get_one_card(Card cd);
    void give_selected_card(CardDeck &to, Card cd);
    void give_one_card(CardDeck &to);

    void print_cards();
    void sort_cards();

private:
    vector<Card> deck;

    void add_one_deck();
};

#endif // CARDDECK_H
