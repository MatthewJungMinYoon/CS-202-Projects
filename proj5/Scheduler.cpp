/* Title: Scheduler.cpp
   Author: Matthew Yoon
   Date: 11/15/2019
   Description: .cpp file for Scheduler.h
*/

#include "Scheduler.h"
const int NEG_ONE = -1;
enum{ZERO, ONE, TWO, THREE, FOUR, FIVE};
//Name: Scheduler
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Scheduler object
Scheduler::Scheduler(){
}

//Name: Scheduler
//Desc: Overloaded Constructor
//Precondition: Valid fileName
//Postcondition: Creates Scheduler object
Scheduler::Scheduler(string fileName){
  m_fileName = fileName;
}

//Name: ~Scheduler
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates everything dynamically allocated in Scheduler
Scheduler::~Scheduler(){
  for(unsigned int i = 0; i < m_classes.size(); i++){
    delete m_classes.at(i);
    m_classes.at(i) = nullptr;
  }
}

//Name: LoadFile
//Desc: Loads a roster file
//Precondition: Valid roster file
//Postcondition: Populates roster
void Scheduler::LoadFile(){
  ifstream myFile(m_fileName);

  string fName;
  string lName;
  string strID;
  string course;

  if(myFile.is_open()){
    while(getline(myFile, fName, ',')){
      getline(myFile, lName, ',');
      getline(myFile, strID, ',');
      getline(myFile, course, '\n');

      int ID = atoi(strID.c_str());

      Student *newStud = new Student(fName, lName, ID);
      AddStudent(newStud, course);
    }
  }

  else{
    cout << "File not open" << endl;
  }
}

//Name: MainMenu
//Desc: Displays the main menu of the program
//      Has options for 1. Display All Courses, 2. Display Specific Course
//      3. Search for Specific Student, 4. Sort Roster, and 5. Quit
//Precondition: Has roster loaded
//Postcondition: Keeps running until user chooses 5 (quit)
void Scheduler::MainMenu(){
  int userInput;

  do{
    do{
      cout << "1. Display All Courses" << endl;
      cout << "2. Display a Specific Course" << endl;
      cout << "3. Search for  Specific Courses" << endl;
      cout << "4. Sort Roster" << endl;
      cout << "5. Quit" << endl;
      cin >> userInput;
    }while((userInput < 1) || (userInput > 5)); //input validation

    switch(userInput){
    case ONE:
      //display courses
      DisplayCourses();
      break;

    case TWO:
      //display specific course
      DisplaySpecific();
      break;

    case THREE:
      //search for student
      SearchStudent();
      break;

    case FOUR:
      //alphabetically sort
      SortRoster();
      break;

    default:
      cout << endl;
    }
  }while(userInput != FIVE); //break out of loop if input is 5
}

//Name: DisplayCourses()
//Desc: Displays each course in the m_classes (Just name and section)
//Precondition: Classes loaded into m_classes
//Postcondition: Displays Class info
void Scheduler::DisplayCourses(){
  for(unsigned int i = 0; i < m_classes.size(); i++){
    cout << *m_classes.at(i) << endl;
  }
}

//Name: DisplaySpecific
//Desc: Prompts user for a specific course (lists each class by name/section)
//      Displays each student enrolled in course
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays student info by class
void Scheduler::DisplaySpecific(){
  unsigned int course;
  cout << "Which course would you like to display?" << endl;
  do{
    for(unsigned int i = 0; i < m_classes.size(); i++){
      cout << i + 1 << ". " << *m_classes.at(i) << endl;
    }
    cin >> course;
  }while((course < ONE) || (course > m_classes.size()));

  cout << "Displaying Students" << endl;
  m_classes.at(course - 1)->DisplayStudents();
}

//Name: SearchStudent
//Desc: Prompts user for a specific string to search for (student name)
//      Returns each course that name appears
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays classes that student is in
void Scheduler::SearchStudent(){
  string search;
  cout << "What name do you want to search for?" << endl;
  cin >> search;

  cout << "Items with " << search << " in them: " << endl;
  for(unsigned int i = 0; i < m_classes.size(); i++){
    if(m_classes.at(i)->SearchClass(search) == true){
      cout << *m_classes.at(i) << endl;;
    }
  }
}

//Name: SortRoster
//Desc: For each Class, each m_roster and m_waitlist is sorted by last name
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Does not display anything but rosters are sorted
void Scheduler::SortRoster(){
  for(unsigned int i = 0; i < m_classes.size(); i ++){
    m_classes.at(i)->SortStudents();
  }
}

//Name: Start
//Desc: Welcomes users, loadsfile and calls mainmenu
//Precondition: None
//Postcondition: m_classes is populated
void Scheduler::Start(){
  cout << "Welcome to the UMBC Scheduler" << endl;
  LoadFile();
  MainMenu();
}

//Name: FindClass
//Desc: Helper function that searches for a class name in m_classes and
//      returns the index of where the Class exists to add the student
//      HINT: May want to implement to go backwards through m_classes
//Precondition: None
//Postcondition: Returns the index of the "current" section of a class
int Scheduler::FindClass(string className){
  for(int i = (int)m_classes.size() - 1; i >= 0; i--){
    //return index if names match
    if(m_classes.at(i)->GetName() == className){
      return i;
    }
  }

  return -1;
}

//Name: AddStudent
//Desc: Helper function from LoadFile that decides what to do with a new student
//      Scenario 1 - No classes in m_classes - Creates new class and adds student
//      Scenario 2 - Add Student to existing class where m_roster and m_waitlist
//      are not full
//      Scenario 3 - Add Student when existing class is full ->create new class and
//      move m_waitlist to new section
//Precondition: None
//Postcondition: Student added to a class
void Scheduler::AddStudent(Student* newStud, string course){
  bool add;

  //if m_classes is empty
  if(m_classes.empty() == true){

    Class *newClass = new Class(course, ONE);
    m_classes.push_back(newClass);
    add = m_classes.at(0)->AddStudent(newStud);
  }

  //if m_classes is populated
  else{

    int index = FindClass(course);

    //if vector has classes, but not the one you're looking for, add it
    if(index == -1){
      Class *newClass = new Class(course, ONE);
      m_classes.push_back(newClass);
      index = FindClass(course);
      add = m_classes.at(index)->AddStudent(newStud);
    }

    //if the class is already in the vector
    else{

      //if roster or waitlist is not full add student
      if((m_classes.at(index)->IsRosterFull() == false) || (m_classes.at(index)->IsWaitlistFull() == false)){
        add = m_classes.at(index)->AddStudent(newStud);
      }

      //if both roster and waitlist is full make new section
      else if((m_classes.at(index)->IsRosterFull() == true) && (m_classes.at(index)->IsWaitlistFull() == true)){
        int numSection = m_classes.at(index)->GetSection() + 1;
        Class *newSection = new Class(course, numSection);
        //newSection->SetSection(m_classes.at(index)->GetSection() + 1);
        m_classes.push_back(newSection);
        int newSec = FindClass(course);
        m_classes.at(index)->TransferWaitToRoster(*m_classes.at(newSec));
        add = m_classes.at(newSec)->AddStudent(newStud);
      }
    }
  }
  if(add == true){
    cout << "";
  }
}
