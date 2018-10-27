#include "Card.h"

Card::Card(card_points p, card_color c)
{
    points = p;
    color = c;
}

card_points Card::get_points()
{
    return points;
}

card_color Card::get_color()
{
    return color;
}
