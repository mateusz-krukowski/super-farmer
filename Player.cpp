#include "Player.h"

Player::Player(unsigned char index) {
    this->index = index+1;
    this->bigDog = false;
    this->smallDog = false;
    this->rabbits = 0;
    this->sheeps = 0;
    this->pigs = 0;
    this->cows = 0;
    this->horses = 0;
    this->redDice = &RedDice::getInstance();
    this->greenDice = &GreenDice::getInstance();
}

std::string Player::toString() const {
    std::string result = "Player " + std::to_string(index) + "\n";
    result += "bigDog: " + std::to_string(bigDog) + "\n";
    result += "smallDog: " + std::to_string(smallDog) + "\n";
    result += "rabbits: " + std::to_string(rabbits) + "\n";
    result += "sheeps: " + std::to_string(sheeps) + "\n";
    result += "pigs: " + std::to_string(pigs) + "\n";
    result += "cows: " + std::to_string(cows) + "\n";
    result += "horses: " + std::to_string(horses) + "\n";
    return result;
}
bool Player::won() {
    return (rabbits > 0 && sheeps > 0 && pigs > 0 && cows > 0 && horses > 0);
}

std::string Player::animalToString(Animal animal)
{
    switch (animal)
    {
    case Animal::Rabbit:
        return "Rabbit";
    case Animal::Sheep:
        return "Sheep";
    case Animal::Pig:
        return "Pig";
    case Animal::Cow:
        return "Cow";
    case Animal::Horse:
        return "Horse";
    case Animal::Fox:
        return "Fox";
    case Animal::Wolf:
        return "Wolf";
    default:
        return "Unknown";
    }
}

void Player::rollTheDice()
{
    Animal redDiceResult = this->redDice->roll();
    Animal greenDiceResult = this->greenDice->roll();
    std::cout << "You rolled: " << std::endl;
    std::cout << animalToString(redDiceResult) << std::endl;
    std::cout << animalToString(greenDiceResult) << std::endl;
}

bool Player::hasSmallDog() const {
    return this->smallDog;
}

bool Player::hasBigDog() const {
    return this->bigDog;
}

unsigned char Player::getIndex() const {
    return this->index;
}

unsigned char Player::getRabbits() const {
    return this->rabbits;
}

unsigned char Player::getSheeps() const {
    return this->sheeps;
}

unsigned char Player::getPigs() const {
    return this->pigs;
}

unsigned char Player::getCows() const {
    return this->cows;
}

unsigned char Player::getHorses() const {
    return this->horses;
}

void Player::setSmallDog(bool value) {
    this->smallDog = value;
}

void Player::setBigDog(bool value) {
    this->bigDog = value;
}

void Player::setIndex(unsigned char value) {
    this->index = value;
}

void Player::setRabbits(unsigned char value) {
    this->rabbits = value;
}

void Player::setSheeps(unsigned char value) {
    this->sheeps = value;
}

void Player::setPigs(unsigned char value) {
    this->pigs = value;
}

void Player::setCows(unsigned char value) {
    this->cows = value;
}

void Player::setHorses(unsigned char value) {
    this->horses = value;
}
