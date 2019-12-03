CXX = g++
CXXFLAGS = -Wall
OBJECTS = Student.o Class.o Scheduler.o Tqueue.cpp

proj5: $(OBJECTS) proj5.cpp
        $(CXX) $(CXXFLAGS) $(OBJECTS) proj5.cpp -o proj5

Scheduler.o: Class.o Student.o Scheduler.h Scheduler.cpp
        $(CXX) $(CXXFLAGS) -c Scheduler.cpp

Class.o: Student.o Class.h Class.cpp Tqueue.cpp
        $(CXX) $(CXXFLAGS) -c Class.cpp

Student.o: Student.h Student.cpp
        $(CXX) $(CXXFLAGS) -c Student.cpp

clean:
        rm *.o*
        rm *~

run1:
        ./proj5 proj5_test1.txt

run2:
        ./proj5 proj5_test2.txt

run3:
        ./proj5 proj5_test3.txt

run4:
        ./proj5 proj5_test4.txt

val1:
        valgrind ./proj5 proj5_test1.txt

val2:
        valgrind ./proj5 proj5_test2.txt

val3:
        valgrind ./proj5 proj5_test3.txt

val4:
        valgrind ./proj5 proj5_test4.txt
