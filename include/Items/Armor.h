#ifndef INC_MOVINGGAME_ARMOR_H
#define INC_MOVINGGAME_ARMOR_H
#include "Equippable.h"



class Armor : public Equippable {
public:
    Armor(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, int protectionP, int thicknessP);
    int getProtection() const;
    int getThickness() const;
    
private:
    int protection;//damage to nullify from attacker
    int thickness;//value that the attacker must obtain to land a hit

    const std::vector<std::string> armorEnchants = {"PROTECTION", "THICKNESS"};
};


#endif