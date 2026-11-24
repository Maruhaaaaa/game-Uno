#include "Cards.h"

bool Card::Can_Play(const Card& top_card, Color active_color) const{
    if (this->color == Color::Wild) {return true;}
    return (active_color == this->color) || (this->value == top_card.getValue());
}

std::string Card::Data_card() const{
    std::string color_str;
    switch (color)
    {
    case Color::Green: color_str = "Green"; break;
    case Color::Yellow: color_str = "Yellow"; break;
    case Color::Blue: color_str = "Blue"; break;
    case Color::Red: color_str = "Red"; break;
    case Color::Wild: color_str = "Wild"; break;
    };

    std::string value_str;
    switch (value)
    {
    case Value::Zero: value_str = "0"; break;
    case Value::One: value_str = "1"; break;
    case Value::Two: value_str = "2"; break;
    case Value::Three: value_str = "3"; break;
    case Value::Four: value_str = "4"; break;
    case Value::Five: value_str = "5"; break;
    case Value::Six: value_str = "6"; break;
    case Value::Seven: value_str = "7"; break;
    case Value::Eight: value_str = "8"; break;
    case Value::Nine: value_str = "9"; break;
    case Value::Reverse: value_str = "Reverse"; break;
    case Value::Skip: value_str = "Skip"; break;
    case Value::Plus_Two: value_str = "+2"; break;
    case Value::Wild_Change_Color: value_str = "Change color"; break;
    case Value::Wild_Plus_Four: value_str = "+4"; break;
    }

    return color_str + ", " + value_str;
}
