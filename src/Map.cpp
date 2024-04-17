#include "../include/Map.h"

Map::Map(std::string mapNameP, int mapHeightP, int mapWidthP, Position entranceP, Position exitP, Position objectiveP) : mapName(Functions::convertToUpper(mapNameP)), mapHeight(mapHeightP), mapWidth(mapWidthP), entrance(entranceP), exit(exitP), objective(objectiveP), cells(initCells())
{
    setCell(entrance.first,entrance.second, PLAYER);
    setCell(exit.first, exit.second, LOCKED_DOOR);
    setCell(objective.first, objective.second, OBJECTIVE);
    //movePlayer(Direction::UP, 5);
}

MapCells Map::initCells()
{
    MapCells result;
    result.resize(mapHeight);
    for (int i = 0 ; i < mapHeight ; i++) {
        result.at(i).resize(mapWidth, EMPTY);
    }
    return result;
}

std::string Map::getMapName() const
{
    return mapName;
}

void Map::setCell(int col, int row, MapCell toSet)
{
    if (row < mapHeight && row >= 0 && col < mapWidth && col >= 0) {
        cells[row][col] = toSet;
    } else {
        throw std::invalid_argument("In Map::setCell(): The passed row: "+std::to_string(row)+", and the passed col: "+std::to_string(col)+" are not within the boundaries of the map\n");
    }
    
}

Position Map::getPositionOf(std::string& characterName)
{
    for (int i = 0 ; i < cells.size() ; i++) {
        for (int j = 0 ; j < cells.at(i).size() ; j++) {
            if (cells.at(i).at(j).getSymbol() == 'P') {
                Character* player = static_cast<Character*>(&cells.at(i).at(j));
                if (player->getCharacterName() == characterName) {
                    //Position result(x,y)
                    //return result;
                }
            }
        }
    }
}

void Map::moveCharacter(std::string& characterName, Direction direction, int numOfSpaces)
{
    int dx = 0, dy = 0;
    switch (direction) {
        case Direction::UP:
        dy = -numOfSpaces;
        case Direction::DOWN:
        dy = numOfSpaces;
        case Direction::LEFT:
        dx = -numOfSpaces;
        case Direction::RIGHT:
        dx = numOfSpaces;
    }



}

std::string Map::cellsToString() const
{
    std::string result = "Map:\n";
    for (auto& row : cells) {
        for (auto& cell : row) {
            result += cell.getSymbol();
            result += ' ';
        }
        result += "\n";
    }
    result += "Map end\n";

    return result;
}

void Map::displayMap() const
{
    std::cout << "MAP " << mapName << "\n";
    for (int i = -2 ; i < 3*mapWidth ; i++) { std::cout << "="; }
    std::cout << "\n";
    for (auto& row : cells) {
        std::cout << "|";
        for (auto& cell : row) {
            std::cout << ' ' << cell.getSymbol() << ' ';
        }
        std::cout << "|\n";
    }
    for (int i = -2 ; i < 3*mapWidth ; i++) { std::cout << "="; }
    std::cout << "\n";
}