#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student{
 public:
  // Name: Student
  // Description: Default Constructor
  // Preconditions: None
  // Postconditions: Creates new student object
  Student();
  // Name: Student (fName, lName, id)
  // Description: Overloaded Constructor
  // Preconditions: Data being passed is valid
  // Postconditions: Creates new student object
  Student(string fName, string lName, int id);
  // Name: Getters and Setters
  // Description: Either returns data or sets data in class
  // Preconditions: Setter data is valid
  // Postconditions: Either returns data or sets data
  string GetFName();
  string GetLName();
  int GetID();
  void SetFName(string fName);
  void SetLName(string lName);
  void SetID(int id);
  // Name: Overloaded <<
  // Description: Prints the details of a student
  // Preconditions: all variables are set valid
  // Postconditions: returns an ostream with output of student
  friend ostream& operator<<(ostream&, Student&);
  // Name: Overloaded <
  // Description: Overloaded comparison operator (used for sorting)
  // Preconditions: Two students being compared
  // Postconditions: Returns m_lName first and then m_fName if m_lName same
  friend bool operator< (const Student &s1, const Student &s2);
private:
  string m_fName; //First name of student
  string m_lName; //Last name of student
  int m_id; //Student ID
};

#endif
