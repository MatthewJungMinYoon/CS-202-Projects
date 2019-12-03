CXX = g++
CXXFLAGS = -Wall

proj2: Game.o proj2.cpp
        $(CXX) $(CXXFLAGS) Foundable.o Wizard.o Game.o proj2.cpp -o proj2

Game.o: Wizard.o Foundable.o Game.h Game.cpp
        $(CXX) $(CXXFLAG) -c Game.cpp

Wizard.o: Wizard.h Wizard.cpp Foundable.o
        $(CXX) $(CXXFLAGS) -c Wizard.cpp

Foundable.o: Foundable.cpp Foundable.h
        $(CXX) $(CXXFLAGS) -c Foundable.cpp

clean:
        rm *.o*
        rm *~

run:
        ./proj2
