#ifndef INC_MOVINGGAME_EQUIPPABLE_H
#define INC_MOVINGGAME_EQUIPPABLE_H
#include <vector>
#include <stdexcept>

#include "Item.h"

class Equippable : public Item {
public:
    Equippable(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, std::vector<std::string> possibleEnchantsP);
    bool validateEnchant() const;
    std::string getEnchantType() const;
    int getEnchantLevel() const;
    std::vector<std::string> getPossibleEnchants() const;
    bool setEnchant(std::string enchantTypeP, int enchantLevelP);
    void setEnchantLevel(int enchantLevelP);
protected:
    std::string enchantType;//"-" for unenchanted
    int enchantLevel;
    std::vector<std::string> possibleEnchants;
};


#endif