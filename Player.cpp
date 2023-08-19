#include "Player.h"

Player::Player(unsigned char index) {
    this->index = index+1;
    this->bigDog = false;
    this->smallDog = false;
    this->redDice = &RedDice::getInstance();
    this->greenDice = &GreenDice::getInstance();

    //filling the animals map 
    for (int i = 0; i < 5; ++i) {
        animals[static_cast<Animal>(i)] = 0;
     }
}

std::string Player::toString() const {
    std::string result = "Player " + std::to_string(index) + "\n";
    result += "bigDog: " + std::to_string(bigDog) + "\n";
    result += "smallDog: " + std::to_string(smallDog) + "\n";
    result += "rabbits: " + std::to_string(animals.at(Animal::Rabbit)) + "\n";
    result += "sheeps: " + std::to_string(animals.at(Animal::Sheep)) + "\n";
    result += "pigs: " + std::to_string(animals.at(Animal::Pig)) + "\n";
    result += "cows: " + std::to_string(animals.at(Animal::Cow)) + "\n";
    result += "horses: " + std::to_string(animals.at(Animal::Horse)) + "\n";
    return result;
}
bool Player::won() {
    if ((animals.at(Animal::Rabbit) > 0) && (animals.at(Animal::Sheep) > 0) && (animals.at(Animal::Pig) > 0) && (animals.at(Animal::Pig) > 0) && (animals.at(Animal::Cow) > 0) && (animals.at(Animal::Horse) > 0)) {
        return true;
    }
    return false;
}

std::string Player::animalToString(Animal* animal)
{
    switch (*animal)
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

void Player::handleRolledAnimalOnce(Animal animal)
{
    if (animal != Animal::Wolf && animal != Animal::Fox) {
        addAnimalQuantity(animal, floor((this->animals.at(animal) + 1) / 2));
    }
}
void Player::handleRolledAnimalTwice(Animal animal)
{
    addAnimalQuantity(animal, floor((this->animals.at(animal) + 2) / 2));
}

void Player::handleDiceOutcome(Animal red, Animal green) {
    
    // two rabbits || two sheeps || two pigs
    if (red == green) {
        handleRolledAnimalTwice(red); //or green because they're equal
    }
    else {

        if (green == Animal::Wolf) {
            if (!this->hasBigDog()) {
                setAnimalQuantity(Animal::Rabbit, 0);
                setAnimalQuantity(Animal::Sheep, 0);
                setAnimalQuantity(Animal::Pig, 0);
                setAnimalQuantity(Animal::Cow, 0);
            }
            else {
                setBigDog(0);
            }
            if (red == Animal::Horse && (this->animals.at(Animal::Horse) > 0)) {
                handleRolledAnimalOnce(red); // Animal::Horse
            }
            
        }
        if (red == Animal::Fox) {
            if (!this->hasSmallDog()) {
                setAnimalQuantity(Animal::Rabbit, 0);
            }
            else {
                this->setSmallDog(0);
            }
            //add the remaining animals according to what is rolled on the green dice (Sheep, Pig, Cow, Horse)
            handleRolledAnimalOnce(green);
         }
         // handle remaining combinations (neither both the same nor wolf or fox)
        handleRolledAnimalOnce(green);
        handleRolledAnimalOnce(red);
    }
}


void Player::rollTheDice()
{
    Animal redDiceResult = this->redDice->roll();
    Animal greenDiceResult = this->greenDice->roll();
    std::cout << "You rolled: " << std::endl;
    std::cout << "Red dice: " << animalToString(&redDiceResult) << std::endl;
    std::cout << "Green dice: " << animalToString(&greenDiceResult) << std::endl;
    handleDiceOutcome(redDiceResult,greenDiceResult);
}

void Player::addAnimalQuantity(Animal animal , unsigned char quantity)
{
    setAnimalQuantity(animal, animals.at(animal) + quantity);
}
void Player::subtractAnimalQuantity(Animal animal, unsigned char quantity)
{
    setAnimalQuantity(animal, animals.at(animal) - quantity);
}



// Performing trade

void Player::tradeRabbitsForSheep()
{
    if (this->animals.at(Animal::Rabbit) >= 6) {
        this->subtractAnimalQuantity(Animal::Rabbit, 6);
        this->addAnimalQuantity(Animal::Sheep, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;

}

void Player::tradeSheepForRabbits()
{
    if (this->animals.at(Animal::Sheep) >= 1) {
        this->subtractAnimalQuantity(Animal::Sheep, 1);
        this->addAnimalQuantity(Animal::Rabbit, 6);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;

}

void Player::tradeSheepForSmallDog()
{
    if (!this->hasSmallDog()) {
        if (this->animals.at(Animal::Sheep) >= 1) {
            this->subtractAnimalQuantity(Animal::Sheep, 1);
            this->setSmallDog(true);
        }
        else std::cout << "You have too few animals to perform the trade" << std::endl;
    }
    else std::cout << "You already have small dog" << std::endl;
}

void Player::tradeSmallDogForSheep()
{
    if (this->hasSmallDog()) 
    {
        this->setSmallDog(0);
        this->addAnimalQuantity(Animal::Sheep, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradeSheepsForPig()
{
    if (this->animals.at(Animal::Sheep) >= 2) {
        this->subtractAnimalQuantity(Animal::Sheep, 2);
        this->addAnimalQuantity(Animal::Pig, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradePigForSheeps()
{
    if (this->animals.at(Animal::Pig) >= 1) {
        this->subtractAnimalQuantity(Animal::Pig, 1);
        this->addAnimalQuantity(Animal::Sheep, 2);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradePigsForCow()
{
    if (this->animals.at(Animal::Pig) >= 3) {
        this->subtractAnimalQuantity(Animal::Pig, 3);
        this->addAnimalQuantity(Animal::Cow, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}
void Player::tradeCowForPigs() 
{
    if (this->animals.at(Animal::Cow) >= 1) {
        this->subtractAnimalQuantity(Animal::Cow, 1);
        this->addAnimalQuantity(Animal::Pig, 3);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradeCowForBigDog()
{
    if (!this->hasBigDog()) {
        if (this->animals.at(Animal::Cow) >= 1) {
            this->subtractAnimalQuantity(Animal::Cow, 1);
            this->setBigDog(true);
        }
        else std::cout << "You have too few animals to perform the trade" << std::endl;
    }
    else std::cout << "You already have big dog" << std::endl;
}

void Player::tradeBigDogForCow()
{
    if (this->hasBigDog()) {
        this->setBigDog(0);
        this->addAnimalQuantity(Animal::Cow, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradeCowsForHorse()
{
    if (this->animals.at(Animal::Cow) >= 2) {
        this->subtractAnimalQuantity(Animal::Cow, 2);
        this->addAnimalQuantity(Animal::Horse, 1);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}

void Player::tradeHorseForCows()
{
    if (this->animals.at(Animal::Horse) >= 1) {
        this->subtractAnimalQuantity(Animal::Horse, 1);
        this->addAnimalQuantity(Animal::Cow, 2);
    }
    else std::cout << "You have too few animals to perform the trade" << std::endl;
}


// GETTERS

bool Player::hasSmallDog() const {
    return this->smallDog;
}

bool Player::hasBigDog() const {
    return this->bigDog;
}


// SETTERS

void Player::setSmallDog(bool value) {
    this->smallDog = value;
}

void Player::setBigDog(bool value) {
    this->bigDog = value;
}

void Player::setAnimalQuantity(Animal animal, unsigned char quantity) {
    if (animals.find(animal) != animals.end()) {
        animals[animal] = quantity;
    }
    else {
        std::cout << "Error: Unknown animal species." << std::endl;
    }
}