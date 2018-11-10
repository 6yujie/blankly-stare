#ifndef CARD_H
#define CARD_H

#include "mainwindow.h"

//扑克花色
enum card_color
{
    spade,   //黑桃 ♠
    heart,   //红桃 ♥
    club,    //梅花 ♣
    diamond, //方块 ♦
    red,     //大王
    black    //小王
};

enum card_point
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
    Card(card_point p, card_color c);

    QString get_point_str();
    QString get_color_str();

    static card_color card_color_cast(int i);
    static card_point card_point_cast(int i);

    bool operator == (const Card &cd);
    bool operator < (const Card &cd);
    bool operator > (const Card &cd);

    card_point get_point() const;
    card_color  get_color() const;

private:
    card_point point;
    card_color color;
};

#endif // CARD_H
