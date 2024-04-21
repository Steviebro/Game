#include "../../include/Items/Weapon.h"

Weapon::Weapon(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, int baseDamageP, int accuracyP, int critChanceP, std::string diceTypeP) : Equippable(itemNameP, itemTypeP, enchantTypeP, enchantLevelP, weaponEnchants),
baseDamage(baseDamageP), accuracy(accuracyP), critChance(critChanceP), diceType(diceTypeP)
{
    if (baseDamage < 0) {
        baseDamage = 0;
    }
    
    if (accuracy > 5) {
        accuracy = 5;
    } else if (accuracy < 0) {
        accuracy = 0;
    }

    if (critChance > 100) {
        critChance = 100;
    } else if (critChance < 0) {
        critChance = 0;
    }

    try {
        Functions::rollDice(diceType);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
        throw std::invalid_argument("In Weapon constructor: invalid diceType passed. Throws exception in Weapon\n");
    }


}

int Weapon::getBaseDamage() const
{
    return baseDamage;
}

int Weapon::getAccuracy() const
{
    return accuracy;
}

int Weapon::getCritChance() const
{
    return critChance;
}

int Weapon::getRange() const
{
    return range;
}

std::string Weapon::getDiceType() const
{
    return diceType;
}

int Weapon::attackRoll()
{
    return Functions::rollDice("1d20") + accuracy;
}

int Weapon::critRoll()
{
    return Functions::rollDice("1d100") - critChance;//if negative --> crits. Can subtract from this the enchant values of crit chance if there are bonuses.
}

int Weapon::damageRoll()
{
    return Functions::rollDice(diceType) + baseDamage;
}