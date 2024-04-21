#include <string>



class Character {
public:
    Character(std::string characterNameP);
    std::string getCharacterName() const;
private:
    std::string characterName;
    int level;
    int hp;
    int energy;
};