#ifndef CARD_H
#define CARD_H

#include "mainwindow.h"

//扑克花色
enum card_color
{
    heart,   //红桃 ♥
    spade,   //黑桃 ♠
    club,    //梅花 ♣
    diamond, //方块 ♦
    red,     //大王
    black    //小王
};

enum card_points
{
    ace,    //A
    two,    //2
    three,  //3
    four,   //4
    five,   //5
    six,    //6
    seven,  //7
    eight,  //8
    nine,   //9
    ten,    //10
    jack,   //J
    queen,  //Q
    king,   //K
    joker   //王
};

class Card
{
public:
    Card(card_points p, card_color c);
    card_points get_points();
    card_color  get_color();

private:
    card_points points;
    card_color color;
};

#endif // CARD_H
