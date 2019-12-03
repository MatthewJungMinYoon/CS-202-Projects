#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>
#include "Tqueue.cpp"
#include "Student.h"
using namespace std;

//*********Constants*************
const int ROSTER_MAX = 10;
const int WAIT_MAX = 3;

class Class{
 public:
  //Name: Class
  //Desc: Default Constructor
  //Precondition: None
  //Postcondition: Creates Class object
  Class();
  //Name: Class
  //Desc: Overloaded Constructor
  //Precondition: Have name and number
  //Postcondition: Creates Class object
  Class(string name, int section);
  //Name: ~Class
  //Desc: Destructor
  //Precondition: None
  //Postcondition: Deallocates anything dynamically allocated in a Class
  ~Class();
  //Name: DisplayStudents
  //Desc: Displays all students in Class. Displays students in the m_roster
  //      and if there are students in the m_waitlist, displays them
  //      Additionally shows count of students in m_roster and count in m_waitlist
  //Precondition: Class has students enrolled
  //Postcondition: Lists all students for a specific Class
  void DisplayStudents();
  //Name: AddStudent
  //Desc: A student is added to a Class. If there is room in the m_roster, added there.
  //      If the m_roster is full, attempts to add student to m_waitlist.
  //      Else new section added, waitlist moved to new section and new student added.
  //Precondition: Class exists
  //Postcondition: Adds a student to a Class; returns true if added else false
  bool AddStudent(Student*);
  //Name: Sort
  //Desc: Sorts the students alphabetically by last name for both roster and waitlist
  //Precondition: None
  //Postcondition: m_roster and m_waitlist are sorted
  void SortStudents();
  //Name: GetName
  //Desc: Returns name of Class
  //Precondition: None
  //Postcondition: Class name is returned
  string GetName();
  //Name: SetName
  //Desc: Allows Class name to be set
  //Precondition: name is a valid string
  //Postcondition: Class name is updated
  void SetName(string name);
  //Name: GetSection
  //Desc: Returns section of Class
  //Precondition: None
  //Postcondition: Class section is returned
  int GetSection();
  //Name: SetSection
  //Desc: Allows Class section to be set
  //Precondition: section is a valid integer
  //Postcondition: Class section is updated
  void SetSection(int section);
  //Name: TransferWaitToRoster
  //Desc: When an m_roster is full and m_waitlist is full, copies all students in
  //      m_waitlist to a destination Class
  //Precondition: m_waitlist is full
  //Postcondition: m_waitlist is empty and all students were transferred to new Class
  void TransferWaitToRoster(Class& destination);
  //Name: IsRosterFull()
  //Desc: Returns bool of if the m_roster is at capacity
  //Precondition: None
  //Postcondition: Returns bool
  bool IsRosterFull();
  //Name: IsWaitlistFull()
  //Desc: Returns bool of if the m_waitlist is at capacity
  //Precondition: None
  //Postcondition: Returns bool
  bool IsWaitlistFull();
  //Name: SearchClass
  //Desc: Searches m_roster and m_waitlist for a string.
  //      If string exists in m_roster or m_waitlist, Class information printed
  //Precondition: None
  //Postcondition: Returns bool
  bool SearchClass(string item);
  // Name: Overloaded <<
  // Description: Prints the details of a Class (Class name and section)
  // Preconditions: all variables are set valid
  // Postconditions: returns an ostream with output of the Class
  friend ostream& operator<<(ostream&, Class&);
private:
  string m_name; //Equates to CMSC201
  int m_section; //Starts at 1
  Tqueue<Student*,ROSTER_MAX> m_roster; //Queue of students in Class
  Tqueue<Student*,WAIT_MAX> m_waitlist; //Queue of students waiting for Class
};

#endif
