#include "CardPic.h"

CardPic::CardPic(QWidget *parent)
    :QLabel(parent)
{
    pop = false;
}

void CardPic::mouseReleaseEvent(QMouseEvent *event)
{
    if(pop == false)
    {
        this->move(this->pos().x(), this->pos().y() - 20);
        pop = true;
    }
    else
    {
        this->move(this->pos().x(), this->pos().y() + 20);
        pop = false;
    }
}
