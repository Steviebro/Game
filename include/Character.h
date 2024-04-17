#include <string>

#include "MapCell.h"


class Character : public MapCell {
public:
    Character(std::string characterNameP, char characterSymbol);
    std::string getCharacterName() const;
private:
    std::string characterName;
};