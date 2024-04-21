#ifndef INC_MOVINGGAME_ITEMBAG_H
#define INC_MOVINGGAME_ITEMBAG_H
#include <unordered_map>
#include <memory>

#include "../Items/Item.h"
#include "../Items/Equippable.h"

typedef std::unordered_map<std::string, std::unique_ptr<Item>> StrItemPtrMap;

class ItemBag {
public:
    ItemBag(std::string bagNameP, StrItemPtrMap storageP);
    Item* get(std::string itemName);
    std::unique_ptr<Item> remove(std::string itemName);
    bool put(std::unique_ptr<Item> toPut);

    //Safety deletes related to using unique_ptr
    ItemBag(const ItemBag&) = delete;
    ItemBag& operator=(const ItemBag&) = delete;
    ItemBag(ItemBag&& other) noexcept = delete;
    ItemBag& operator=(ItemBag&& other) noexcept = default;
    
protected:
    std::string bagName;
    StrItemPtrMap storage;
};


#endif