#ifndef INC_MOVINGGAME_GOLD_H
#define INC_MOVINGGAME_GOLD_H
#include "Item.h"

class Gold : public Item {
public:
    Gold(std::string itemNameP, std::string itemTypeP, int coinsP);
    int spend(int cost);
    int earn(int earned);
private:
    int coins;
};


#endif