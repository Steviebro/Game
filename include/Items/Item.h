#ifndef INC_MOVINGGAME_ITEM_H
#define INC_MOVINGGAME_ITEM_H
#include <string>

#include "../Functions.h"

class Item {
public:
    Item(std::string itemNameP, std::string itemTypeP);
    virtual ~Item() = default;
    std::string getItemName() const;
    std::string getItemType() const;
protected:
    std::string itemName;
    std::string itemType;
};


#endif