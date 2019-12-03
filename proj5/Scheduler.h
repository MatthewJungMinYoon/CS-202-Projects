#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include "Tqueue.cpp"
#include "Student.h"
#include "Class.h"
using namespace std;

//*********Constants*************
const int MAX_CLASSES = 999;

class Scheduler{
 public:
  //Name: Scheduler
  //Desc: Default Constructor
  //Precondition: None
  //Postcondition: Creates Scheduler object
  Scheduler();
  //Name: Scheduler
  //Desc: Overloaded Constructor
  //Precondition: Valid fileName
  //Postcondition: Creates Scheduler object
  Scheduler(string fileName);
  //Name: ~Scheduler
  //Desc: Destructor
  //Precondition: None
  //Postcondition: Deallocates everything dynamically allocated in Scheduler
  ~Scheduler();
  //Name: LoadFile
  //Desc: Loads a roster file
  //Precondition: Valid roster file
  //Postcondition: Populates roster
  void LoadFile();
  //Name: MainMenu
  //Desc: Displays the main menu of the program
  //      Has options for 1. Display All Courses, 2. Display Specific Course
  //      3. Search for Specific Student, 4. Sort Roster, and 5. Quit
  //Precondition: Has roster loaded
  //Postcondition: Keeps running until user chooses 5 (quit)
  void MainMenu();
  //Name: DisplayCourses()
  //Desc: Displays each course in the m_classes (Just name and section)
  //Precondition: Classes loaded into m_classes
  //Postcondition: Displays Class info
  void DisplayCourses();
  //Name: DisplaySpecific
  //Desc: Prompts user for a specific course (lists each class by name/section)
  //      Displays each student enrolled in course
  //Precondition: Classes loaded into m_classes and rosters populated
  //Postcondition: Displays student info by class
  void DisplaySpecific();
  //Name: SearchStudent
  //Desc: Prompts user for a specific string to search for (student name)
  //      Returns each course that name appears
  //Precondition: Classes loaded into m_classes and rosters populated
  //Postcondition: Displays classes that student is in
  void SearchStudent();
  //Name: SortRoster
  //Desc: For each Class, each m_roster and m_waitlist is sorted by last name
  //Precondition: Classes loaded into m_classes and rosters populated
  //Postcondition: Does not display anything but rosters are sorted
  void SortRoster();
  //Name: Start
  //Desc: Welcomes users, loadsfile and calls mainmenu
  //Precondition: None
  //Postcondition: m_classes is populated
  void Start();
  //Name: FindClass
  //Desc: Helper function that searches for a class name in m_classes and
  //      returns the index of where the Class exists to add the student
  //      HINT: May want to implement to go backwards through m_classes
  //Precondition: None
  //Postcondition: Returns the index of the "current" section of a class
  int FindClass(string);
  //Name: AddStudent
  //Desc: Helper function from LoadFile that decides what to do with a new student
  //      Scenario 1 - No classes in m_classes - Creates new class and adds student
  //      Scenario 2 - Add Student to existing class where m_roster and m_waitlist
  //      are not full
  //      Scenario 3 - Add Student when existing class is full ->create new class and
  //      move m_waitlist to new section
  //Precondition: None
  //Postcondition: Student added to a class
  void AddStudent(Student*, string);
private:
  string m_name; //Named for semester
  string m_fileName; //Filename of the roster
  vector<Class*> m_classes; //Vector of all Classes in schedule
};

#endif
