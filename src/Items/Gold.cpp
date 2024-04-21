#include "../../include/Items/Gold.h"

Gold::Gold(std::string itemNameP, std::string itemTypeP, int coinsP) : Item(itemNameP, itemTypeP), coins(coinsP)
{

}

int Gold::spend(int cost)
{
    if (cost <= 0) {
        return coins;
    }
    coins -= cost;
    if (coins < 0) {
        coins = 0;
    }
    return coins;
}

int Gold::earn(int earned)
{
    if (earned <= 0) {
        return coins;
    }
    coins += earned;
    return coins;
}