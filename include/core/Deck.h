#include "Cards.h"
#include <random>
#include <vector>

class Deck {
private:
    std::vector <Card> cards;
    std::mt19937 rng;

public:
    Deck();
    void init();
    void shuffle();
    Card draw();
    void refill(std::vector <Card>& discardCards);

    bool isEmpty() const { return cards.empty(); }
    size_t size() const { return cards.size(); }

};