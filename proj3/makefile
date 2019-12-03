CXX = g++
CXXFLAGS = -Wall

proj3: Decay.o DecayList.o Node.o driver.cpp
        $(CXX) $(CXXFLAGS) Decay.o DecayList.o Node.o driver.cpp -o proj3

Decay.o: Decay.h Decay.cpp DecayList.o Node.o
        $(CXX) $(CXXFLAGS) -c Decay.cpp

DecayList.o: DecayList.h DecayList.cpp Node.o
        $(CXX) $(CXXFLAGS) -c DecayList.cpp

Node.o: Node.h Node.cpp
        $(CXX) $(CXXFLAGS) -c Node.cpp

run:
        ./proj3

val1:
        valgrind ./proj3

clean:
        rm *~
