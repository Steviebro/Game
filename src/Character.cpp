#include "../include/Character.h"

Character::Character(std::string characterNameP, char characterSymbol) : MapCell(characterSymbol), characterName(characterNameP)
{

}

std::string Character::getCharacterName() const
{
    return characterName;
}