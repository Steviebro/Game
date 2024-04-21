#include "../../include/Items/Item.h"

Item::Item(std::string itemNameP, std::string itemTypeP) : itemName(Functions::convertToUpper(itemNameP)), itemType(Functions::convertToUpper(itemTypeP))
{

}

std::string Item::getItemName() const
{
    return itemName;
}

std::string Item::getItemType() const
{
    return itemType;
}