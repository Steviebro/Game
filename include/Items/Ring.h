#ifndef INC_MOVINGGAME_RING_H
#define INC_MOVINGGAME_RING_H
#include "Equippable.h"



class Ring : public Equippable {
public:
    Ring(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP);
private:
    const std::vector<std::string> ringEnchants = {"PROTECTION", "THICKNESS", "DAMAGE", "ACCURACY", "CRIT_CHANCE"};
};


#endif