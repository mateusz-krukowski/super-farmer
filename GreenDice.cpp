#include "GreenDice.h"

GreenDice::GreenDice()
{
}

GreenDice& GreenDice::getInstance()
{
    static GreenDice instance;
    return instance;
}

Animal GreenDice::roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 12); // Losujemy od 1 do 12

    int result = dis(gen); // Wylosowana liczba

    switch (result) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return Animal::Rabbit; break;
    case 7:
    case 8:
    case 9:
        return Animal::Sheep; break;
    case 10:
        return Animal::Pig; break;
    case 11:
        return Animal::Horse; break;
    case 12:
        return Animal::Fox; break;
    default:
        // W razie b³êdu zwracamy jakiœ domyœlny zwierzak
        return Animal::Rabbit; break;

    }
}
