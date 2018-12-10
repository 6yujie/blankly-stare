#ifndef CARDPIC_H
#define CARDPIC_H

#include <QLabel>
#include <QString>
#include <QWidget>

class CardPic : public QLabel
{
public:
    CardPic(QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool pop;
};

#endif // CARDPIC_H
