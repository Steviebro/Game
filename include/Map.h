#ifndef INC_MOVINGGAME_MAP_H
#define INC_MOVINGGAME_MAP_H

#include <unordered_map>
#include <string>

typedef std::pair<int,int> Position;
enum class Direction {
    UP, DOWN, LEFT, RIGHT
};

namespace std {
    template <>
    struct hash<Position> {
        size_t operator()(const Position& pos) const {
            return hash<int>()(pos.first) ^ (hash<int>()(pos.second) << 1);
        }
    };
}

class Map {
public://                                                 to set playerPostion
    Map(std::string mapName, int mapHeightP, int mapWidthP, Position entrance, std::unordered_map<Position,char> staticCellsP);
    //,std::unordered_map<Position,Enemy> enemiesP, std::unordered_map<Position,Friendly> friendliesP, std::unordered_map<Position,ItemBag> chestsP, std::unordered_map<Position,ItemBag> bodiesP
    //We can uncomment these^ later
    /**
     * Checks the passed position in each hashmap
     * @param position a Position to check
     * @return a char corresponding to the occupant type
    */
    char getCellAt(Position position);

    //Enemy getEnemyAt(Position position);
    //Friendly getFriendlyAt(Position position);
    //ItemBag getBagAt(Position position);//both for bodies and chests
    
    /**
     * Moves a Character from a position towards a direction
     * @param position the Position of the Character to move
     * @param direction the Direction to move the Character
     * @return true if the movement was successful, false otherwise
    */
    bool moveCharacter(Position position, Direction direction);
    /**
     * Kills a Character at a position, removing it from the enemies/friendlies, and adding their equipment to bodies.
     * @param position the Position of the Character to kill
     * @return true if the kill was successful, false otherwise
    */
    bool killCharacter(Position position);
    /**
     * Removes an ItemBag at a position, removing it from bodies/chests.
     * @param position the Position of the ItemBag to remove
     * @return true if the removal was successful, false otherwise.
    */
    bool removeBag(Position position);

private:
    std::string mapName;
    int mapHeight;
    int mapWidth;
    Position playerPosition;
    std::unordered_map<Position,char> staticCells;
    //std::unordered_map<Position,Enemy> enemies;
    //std::unordered_map<Position,Friendly> friendlies;
    //std::unordered_map<Position,ItemBag> chests;
    //std::unordered_map<Position,ItemBag> bodies;

};







#endif