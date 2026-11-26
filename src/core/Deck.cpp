#include "core/Deck.h"
#include <algorithm>
#include <stdexcept>

Deck::Deck()
{
    std::random_device rd;
    rng.seed(rd());
    init();
}

void Deck::init()
{
    cards.clear();
    cards.reserve(108);

    Color standartColors[] = {Color::Red, Color::Green, Color::Yellow, Color::Blue};
    Value dublicateValue[] = {Value::One, Value::Two, Value::Three, Value::Four, Value::Five, Value::Six, Value::Seven,
                              Value::Eight, Value::Nine, Value::Skip, Value::Reverse, Value::Plus_Two};

    for (Color c : standartColors)
    {
        cards.emplace_back(c, Value::Zero);

        for (Value v : dublicateValue)
        {
            cards.emplace_back(c, v);
            cards.emplace_back(c, v);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        cards.emplace_back(Color::Wild, Value::Wild_Change_Color);
        cards.emplace_back(Color::Wild, Value::Wild_Plus_Four);
    }
}

void Deck::shuffle()
{
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::draw()
{
    if (isEmpty())
    {
        throw std::out_of_range("Cannot draw from an empty deck!");
    }

    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

void Deck::refill(std::vector<Card> &discardCards)
{
    cards.insert(cards.end(), discardCards.begin(), discardCards.end());
    discardCards.clear();
    shuffle();
}