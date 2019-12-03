CXX = g++
CXXFLAGS = -Wall

proj4: Room.o Entity.o Character.o Monster.o BabyDragon.o Goblin.o Skeleton.o Paladin.o Rogue.o Wizard.o Game.o proj4.cpp
        $(CXX) $(CXXFLAGS) Room.o Entity.o Character.o Monster.o BabyDragon.o Goblin.o Skeleton.o Paladin.o Rogue.o Wizard.o Game.o proj4.cpp -o proj4

Room.o: Room.h Room.cpp
        $(CXX) $(CXXFLAGS) -c Room.cpp

Entity.o: Entity.h Entity.cpp
        $(CXX) $(CXXFLAGS) -c Entity.cpp

Character.o: Character.h Character.cpp Entity.o
        $(CXX) $(CXXFLAGS) -c Character.cpp

Monster.o: Monster.h Monster.cpp Entity.o Character.o
        $(CXX) $(CXXFLAGS) -c Monster.cpp

BabyDragon.o: BabyDragon.h BabyDragon.cpp Entity.o Character.o Monster.o
        $(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Goblin.o: Goblin.h Goblin.cpp Entity.o Character.o Monster.o
        $(CXX) $(CXXFLAGS) -c Goblin.cpp

Skeleton.o: Skeleton.h Skeleton.cpp Entity.o Character.o Monster.o
        $(CXX) $(CXXFLAGS) -c Skeleton.cpp

Paladin.o: Paladin.h Paladin.cpp Entity.o Character.o
        $(CXX) $(CXXFLAGS) -c Paladin.cpp

Rogue.o: Rogue.h Rogue.cpp Entity.o Character.o
        $(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Wizard.h Wizard.cpp Entity.o Character.o
        $(CXX) $(CXXFLAGS) -c Wizard.cpp

Game.o: Game.h Game.cpp Room.o Entity.o Character.o Monster.o BabyDragon.o Goblin.o Skeleton.o Paladin.o Rogue.o Wizard.o
        $(CXX) $(CXXFLAGS) -c Game.cpp

run:
        ./proj4

run1:
        ./proj4 map1_data.txt

run2:
        ./proj4 map2_data.txt

val:
        valgrind ./proj4

val1:
        valgrind ./proj4 map1_data.txt

val2:
        valgrind ./proj4 map2_data.txt
