#include <iostream>

#include "../include/Map.h"
#include "../include/ItemBags/Equipment.h"

int main() {

    std::unordered_map<std::string, std::string> strStrMap;
    std::cout << "Size is " << strStrMap.size() << "\n";
    std::cout << "At position hello is: |" << strStrMap["hello"] << "|\n";
    std::cout << "Size is " << strStrMap.size() << "\n";
    std::cout << "Comparison of hello with \"\": " << (strStrMap["hello"] == "") << "\n";

    Position entrance(0,5);
    Position exit(15,15);
    Position objective(10,10);

    //map.setCell(0,0,'d');
    //map.setCell(29,29,'d');

    std::cout << "HI\n";

    
    std::cout << "HI\n";




    return 0;
}