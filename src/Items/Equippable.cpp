#include "../../include/Items/Equippable.h"

Equippable::Equippable(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, std::vector<std::string> possibleEnchantsP) : Item(itemNameP, itemTypeP), enchantType(Functions::convertToUpper(enchantTypeP)), enchantLevel(enchantLevelP), possibleEnchants(possibleEnchantsP)
{
    if (!validateEnchant()) {
        throw std::invalid_argument("In Equippable Constructor. Enchant type: "+enchantType+" is incompatible with the possible enchants passed.\n");
    }

    if (enchantLevel > 5) {
        enchantLevel = 5;
    } else if (enchantLevel < 0) {
        enchantLevel = 0;
    }

}

bool Equippable::validateEnchant() const
{
    if (enchantType == "-") {
        return true;
    }
    for (auto& possibleEnchant : possibleEnchants) {
        if (possibleEnchant == enchantType) {
            return true;
        }
    }
    return false;
}

std::string Equippable::getEnchantType() const
{
    return enchantType;
}

int Equippable::getEnchantLevel() const
{
    return enchantLevel;
}

std::vector<std::string> Equippable::getPossibleEnchants() const
{
    return possibleEnchants;
}

bool Equippable::setEnchant(std::string enchantTypeP, int enchantLevelP)
{
    std::string previousEnchant = enchantType;
    enchantType = enchantTypeP;
    if (!validateEnchant()) {
        enchantType = previousEnchant;
        return false;
    }
    setEnchantLevel(enchantLevelP);
    return true;
}

void Equippable::setEnchantLevel(int enchantLevelP)
{
    if (enchantLevelP > 5) {
        enchantLevel = 5;
    } else if (enchantLevelP < 0) {
        enchantLevel = 0;
    } else {
        enchantLevel = enchantLevelP;
    }
}