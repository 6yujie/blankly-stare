#include "Card.h"

Card::Card(card_point p, card_color c)
{
    point = p;
    color = c;
}

QString Card::get_point_str()
{
    switch(point)
    {
        case ace:   return "A";
        case two:   return "2";
        case three: return "3";
        case four:  return "4";
        case five:  return "5";
        case six:   return "6";
        case seven: return "7";
        case eight: return "8";
        case nine:  return "9";
        case ten:   return "10";
        case jack:  return "J";
        case queen: return "Q";
        case king:  return "K";
        case joker: return "王";
        default:    return "ERROR";
    }
}

QString Card::get_color_str()
{
    switch(color)
    {
        case heart:   return ("红桃");
        case spade:   return ("黑桃");
        case club:    return ("梅花");
        case diamond: return ("方块");
        case red:     return ("大 ");
        case black:   return ("小 ");
        default:      return "ERROR";
    }
}

card_point Card::get_point() const
{
    return point;
}

card_color Card::get_color() const
{
    return color;
}

card_color Card::card_color_cast(int i)
{
    switch(i)
    {
        case 0: return heart;
        case 1: return spade;
        case 2: return club;
        case 3: return diamond;
        case 4: return red;
        case 5: return black;
        default: return black;
    }
}

card_point Card::card_point_cast(int i)
{
    switch(i)
    {
        case 0:  return ace;
        case 1:  return two;
        case 2:  return three;
        case 3:  return four;
        case 4:  return five;
        case 5:  return six;
        case 6:  return seven;
        case 7:  return eight;
        case 8:  return nine;
        case 9:  return ten;
        case 10: return jack;
        case 11: return queen;
        case 12: return king;
        case 13: return joker;
        default: return joker;
    }
}

bool Card::operator == (const Card &cd)
{
    if(color == cd.get_color() && point == cd.get_point())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Card::operator < (const Card &cd)
{
    //点数：数字越小，牌越小
    if((int)point-(int)cd.point > 0)
    {
        return false;
    }
    else if((int)point-(int)cd.point < 0)
    {
        return true;
    }
    else
    {
        //花色：数字越小，牌越大
        if((int)color - (int)cd.color > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Card::operator > (const Card &cd)
{
    if(*this < cd)
    {
        return false;
    }
    else if(*this == cd)
    {
        return false;
    }
    else
    {
        return true;
    }
}
