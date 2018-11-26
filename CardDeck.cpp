#include "CardDeck.h"

CardDeck::CardDeck(int decks)
{
    for(int i = 0; i < decks; i++)
    {
        add_one_deck();
    }

    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    random_shuffle(deck.begin(), deck.end());
}

//判断牌堆是否为空
bool CardDeck::empty_deck()
{
    return deck.empty();
}

//返回牌堆中牌的数量
int CardDeck::size()
{
    return (int)deck.size();
}

//确认牌堆里有n张某点数的牌，不考虑花色
bool CardDeck::find(Card cd, int n)
{
    if(n > 0)
    {
        for(unsigned int i = 0; i < deck.size(); i++)
        {
            //依次比较牌堆中各牌的点数，每次找到一个一样的就将n减一。
            if(cd.get_point() == deck[i].get_point())
            {
                n--;
            }

            //n减为0时说明牌堆中有n张牌，可以跳出for循环去进行判断
            if(n == 0)
            {
                break;
            }
        }

        //判断是否找到了n张牌cd
        if(n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //牌堆中有0张牌cd永远是对的
    else if(n == 0)
    {
        return true;
    }
    //输入范围错误时直接返回false
    else
    {
        return false;
    }
}

//从别的牌堆得到一张牌
void CardDeck::get_one_card(Card cd)
{
    deck.push_back(cd);
}

//给一张选定的牌到别的牌堆
void CardDeck::give_selected_card(CardDeck &to, Card cd)
{
    vector<Card>::iterator it = std::find(deck.begin(), deck.end(), cd);
    if(it != deck.end())
    {
        to.get_one_card(cd);
        deck.erase(it);
    }
}

//发一张牌给别的牌堆
void CardDeck::give_one_card(CardDeck &to)
{
    if(!deck.empty())
    {
        to.get_one_card(deck[0]);
        deck.erase(deck.begin());
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
        for(int j = spade; j <= diamond; j++)
        {
            Card tmp_card(Card::card_point_cast(i), Card::card_color_cast(j));
            deck.push_back(tmp_card);
        }
    }
}

//判断是否包含子牌堆sub
bool CardDeck::contains(vector<Card> sub)
{
    if(sub.size() > deck.size())
    {
        return false;
    }

    //将sub先排序，可以将相同点数的牌集中
    sort(sub.begin(), sub.end());

    for(unsigned int i = 0; i < sub.size(); i++)
    {
        int count = 1;
        unsigned int j = i;

        while(i < sub.size() - 1 && sub[i].get_point() == sub[i+1].get_point())
        {
            count++;
            i++;
        }

        if(find(sub[j], count) != true)
        {
            return false;
        }
    }

    return true;
}

void CardDeck::print_cards()
{
    for(unsigned int i = 0; i < deck.size(); i++)
    {
        qDebug()<<deck[i].get_color_str() + " " + deck[i].get_point_str();
    }
    qDebug()<<deck.size()<<" total";
}

void CardDeck::sort_cards()
{
    sort(deck.begin(), deck.end());
}
