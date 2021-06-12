# CMakeList.txt : CMake project for Symulacja, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Symulacja")

# Add source to this project's executable.
add_executable (Symulacja "Symulacja.cpp" "Map.cpp" "MainClass.h" "MainClass.cpp" "People.h" "People.cpp" "Zombie.h" "Zombie.cpp" "Soldiers.h" "Soldiers.cpp" "Civilians.h" "Civilians.cpp" "WeakZombie.h" "WeakZombie.cpp" "StrongZombie.h" "StrongZombie.cpp" "Food.h" "Food.cpp" "Weapons.h" "Weapons.cpp" "ArrangeData.h" "ArrangeData.cpp")

# TODO: Add tests and install targets if needed.
