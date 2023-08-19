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
    return 0; //TODO
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

}

void Player::tradeSheepForRabbits()
{
    player->subtractAnimalQuantity(Animal::Sheep, 1);
    player->addAnimalQuantity(Animal::Rabbit, 6);

}

void Player::tradeSheepForSmallDog()
{
}

void Player::tradeSmallDogForSheep()
{
}

void Player::tradeSheepsForPig()
{
}

void Player::tradePigForSheeps()
{
}

void Player::tradePigsForCow()
{
}

void Player::tradeCowForBigDog()
{
}

void Player::tradeBigDogForCow()
{
}

void Player::tradeCowsForHorse()
{
}

void Player::tradeHorseForCows()
{
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