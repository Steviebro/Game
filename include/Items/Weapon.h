#ifndef INC_MOVINGGAME_WEAPON_H
#define INC_MOVINGGAME_WEAPON_H
#include <iostream>

#include "Equippable.h"



class Weapon : public Equippable {
public:
    Weapon(std::string itemNameP, std::string itemTypeP, std::string enchantTypeP, int enchantLevelP, int baseDamageP, int accuracyP, int critChanceP, std::string diceTypeP);
    int getBaseDamage() const;
    int getAccuracy() const;
    int getCritChance() const;
    int getRange() const;
    std::string getDiceType() const;
    
    int attackRoll();
    int critRoll();
    int damageRoll();
private:
    int baseDamage;//base damage dealt in the event of a hit
    int accuracy;//(0-5): bonus to add to hit dice roll
    int critChance;//(1-100): % chance of a crit in the event of a hit
    int range;//1-5
    std::string diceType;//additional damage dealt in the event of a hit

    //hit: 1d20 + attacker.weapon.accuracy > defender.armor.thickness
    //crit: 1d100 <= attacker.critChance
    //dmg: (attacker.weapon.diceType + attacker.weapon.baseDamage) - defender.armor.protection
    //crit dmg: 2*(attacker.weapon.diceType + attacker.weapon.baseDamage) - defender.armor.protection


    const std::vector<std::string> weaponEnchants = {"DAMAGE", "ACCURACY", "CRIT_CHANCE"};
};


#endif