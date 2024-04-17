#include <iostream>

#include "../include/Map.h"

int main() {
    Position entrance(0,5);
    Position exit(15,15);
    Position objective(10,10);
    Map map("testmap", 20, 20, entrance, exit, objective);

    //map.setCell(0,0,'d');
    //map.setCell(29,29,'d');

    std::cout << "HI\n";

    map.displayMap();
    std::cout << "HI\n";
    return 0;
}