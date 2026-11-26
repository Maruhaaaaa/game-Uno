#include <string>

enum class Color
{
    Green,
    Red,
    Yellow,
    Blue,
    Wild
};

enum class Value
{
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Reverse,
    Skip,
    Plus_Two,
    Wild_Plus_Four,
    Wild_Change_Color
};

class Card
{
private:
    Color color;
    Value value;

public:
    Card(Color c, Value v) : color(c), value(v) {}

    Color getColor() const { return color; }
    Value getValue() const { return value; }

    bool Can_Play(const Card &top_card, Color active_color) const;
    std::string Data_card() const;
};