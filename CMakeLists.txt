cmake_minimum_required(VERSION 3.27)
project(MovingGame)


set(CMAKE_CXX_STANDARD 17)

include_directories(src)

#cpp files only
add_executable(MovingGame
        src/main.cpp
        src/Functions.cpp
        src/Map.cpp
        src/Character.cpp

        src/Items/Item.cpp
        src/Items/Gold.cpp
        src/Items/Equippable.cpp
        src/Items/Ring.cpp
        src/Items/Armor.cpp
        src/Items/Weapon.cpp

        src/ItemBags/ItemBag.cpp
        src/ItemBags/Equipment.cpp
        
)

