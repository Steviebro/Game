#include "../../include/ItemBags/Equipment.h"

Equipment::Equipment(std::string bagNameP, StrItemPtrMap storageP, StrStrMap equippedP) : ItemBag(bagNameP, std::move(storageP)), equipped(equippedP)
{

}

Equipment::Equipment(std::string bagNameP, StrItemPtrMap storageP) : ItemBag(bagNameP, std::move(storageP))
{

}
//no use for this yet i think
bool Equipment::isEquipped(std::string itemType)
{
    Functions::convertToUpper(itemType);

    if (itemType == "ARMOR" || itemType == "WEAPON" || itemType == "RING") {
        if (equipped[itemType] == "") { return false; }
        return true;
    }else {
        throw std::invalid_argument("In Equipment::isEquipped(itemType), invalid itemType passed: "+itemType+"\n");
    }
}

bool Equipment::equipItem(std::string itemName)
{
    Item* itemPtr = get(itemName);
    Equippable* equippablePtr = dynamic_cast<Equippable*>(itemPtr);

    if (equippablePtr != nullptr) {
        std::string itemName = equippablePtr->getItemName();
        std::string itemType = equippablePtr->getItemType();
        equipped[itemType] = itemName;
        return true;
    }
    return false;
}

bool Equipment::unequipItem(std::string itemName)
{
    for (auto it = equipped.begin() ; it != equipped.end() ; it++) {
        if (it->second == itemName) {
            equipped[it->first] = "";
            return true;
        }
    }
    return false;
}

int Equipment::sumEnchants(std::string enchantType)
{
    int sum = 0;
    Functions::convertToUpper(enchantType);
    for (auto& it : equipped) {
        auto itemPtr = get(it.second);
        Equippable* equippablePtr = dynamic_cast<Equippable*>(itemPtr);
        if (equippablePtr != nullptr && equippablePtr->getEnchantType() == enchantType) {
            sum += equippablePtr->getEnchantLevel();
        }
    }
    return sum;
}