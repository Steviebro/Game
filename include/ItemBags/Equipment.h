#ifndef INC_MOVINGGAME_EQUIPMENT_H
#define INC_MOVINGGAME_EQUIPMENT_H

#include "ItemBag.h"
#include "../Items/Equippable.h"

typedef std::unordered_map<std::string, std::string> StrStrMap;

class Equipment : public ItemBag {
public:
    Equipment(std::string bagNameP, StrItemPtrMap storageP, StrStrMap equippedP);
    Equipment(std::string bagNameP, StrItemPtrMap storageP);

    bool isEquipped(std::string itemType);
    bool equipItem(std::string itemName);
    bool unequipItem(std::string itemName);


    int sumEnchants(std::string enchantType);
    
private:
    StrStrMap equipped;
};


#endif