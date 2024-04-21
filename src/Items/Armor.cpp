#include "../../include/Items/Armor.h"

Armor::Armor(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, int protectionP, int thicknessP) : Equippable(itemNameP, itemTypeP, enchantTypeP, enchantLevelP, armorEnchants), protection(protectionP), thickness(thicknessP)
{

}

int Armor::getProtection() const
{
    if (enchantType == "PROTECTION") {
        return protection + enchantLevel;
    }
    return protection;
}

int Armor::getThickness() const
{
    if (enchantType == "THICKNESS") {
        return thickness + enchantLevel;
    }
    return thickness;
}