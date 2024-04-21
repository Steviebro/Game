#include "../include/Character.h"

Character::Character(std::string characterNameP) : characterName(characterNameP)
{

}

std::string Character::getCharacterName() const
{
    return characterName;
}