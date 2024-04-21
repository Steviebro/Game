#include "../../include/ItemBags/ItemBag.h"

ItemBag::ItemBag(std::string bagNameP, StrItemPtrMap storageP) : bagName(bagNameP), storage(std::move(storageP))
{

}

Item* ItemBag::get(std::string itemName)
{
    auto it = storage.find(itemName);
    if (it != storage.end()) {
        return it->second.get();
    }
    return nullptr;
}

std::unique_ptr<Item> ItemBag::remove(std::string itemName)
{
    auto it = storage.find(itemName);
    if (it != storage.end()) {
        auto item = std::move(it->second);
        storage.erase(it);
        return item;
    }
    return nullptr;
}

bool ItemBag::put(std::unique_ptr<Item> toPut)
{
    std::string itemName = toPut->getItemName();
    if (storage.find(itemName) == storage.end()) {
        storage[itemName] = std::move(toPut);
        return true;
    }
    return false;
}