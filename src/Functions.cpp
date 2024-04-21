#include "../include/Functions.h"

bool Functions::isSeeded = false;

std::string Functions::convertToUpper(std::string& toConvert)
{
    std::string result = toConvert;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string Functions::convertToLower(std::string& toConvert)
{
    std::string result = toConvert;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int Functions::rollDice(std::string diceType)
{
    if (!isSeeded) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        isSeeded = true;
    }

    char d;
    int numOfDices = 0;
    int numOfFaces = 0;
    int result = 0;

    std::istringstream stream(diceType);

    if (stream >> numOfDices >> d >> numOfFaces) {
        if (d == 'd') {
            while (numOfDices > 0) {
                result += (std::rand() % numOfFaces) + 1;
                numOfDices--;
            }
        } else {
            throw std::invalid_argument("diceType passed: "+diceType+" is invalid, expected a 'd' as a separator\n");
        }
    } else {
        throw std::invalid_argument("diceType passed: "+diceType+" is invalid. Expected int-d-int\n");
    }

    return result;
}