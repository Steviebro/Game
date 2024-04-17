#ifndef INC_MOVINGGAME_MAP_H
#define INC_MOVINGGAME_MAP_H
#include <string>
#include <vector>
#include <stdexcept>

#include <iostream>

#include "Functions.h"
#include "MapCell.h"
#include "Character.h"

//enums
enum class Direction {
    UP, DOWN, LEFT, RIGHT
};

//chars used
const MapCell EMPTY(' ');
const MapCell WALL('#');
const MapCell LOCKED_DOOR('L');
const MapCell UNLOCKED_DOOR('D');
const MapCell OBJECTIVE('O');

//these are likely NOT GOOD because they should be assigned the values of the char/item MapCell
const MapCell CHEST('C');
const MapCell PLAYER('P');
const MapCell ENEMY('E');
const MapCell FRIENDLY('F');





//typedefs
typedef std::vector<std::vector<MapCell>> MapCells;
typedef std::pair<int,int> Position;



class Map {
public:
    Map(std::string mapNameP, int mapWidthP, int mapHeightP, Position entrance, Position exit, Position objective);
    MapCells initCells();
    std::string getMapName() const;
    std::string getCell(int row, int col);

    void setCell(int row, int col, MapCell toSet);

    Position getPositionOf(std::string& characterName);
    void moveCharacter(std::string& characterName, Direction direction, int numOfSpaces);

    std::string cellsToString() const;
    void displayMap() const;
private:
    std::string mapName;
    int mapWidth;
    int mapHeight;

    MapCells cells;

    Position entrance;
    Position exit;
    Position objective;
    Position playerPosition;
};

#endif