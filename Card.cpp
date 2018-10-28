#include "Card.h"

Card::Card(card_points p, card_color c)
{
    points = p;
    color = c;
}

card_points Card::get_points() const
{
    return points;
}

card_color Card::get_color() const
{
    return color;
}

bool Card::operator == (const Card &cd)
{
    if(color == cd.get_color() && points == cd.get_points())
    {
        return true;
    }
    else
    {
        return false;
    }
}
