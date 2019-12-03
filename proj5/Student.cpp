/* Title: Student.cpp
   Author: Matthew Yoon
   Date: 11/15/2019
   Description: .cpp file for Student.h
*/

#include "Student.h"

// Name: Student
// Description: Default Constructor
// Preconditions: None
// Postconditions: Creates new student object
Student::Student(){
}

// Name: Student (fName, lName, id)
// Description: Overloaded Constructor
// Preconditions: Data being passed is valid
// Postconditions: Creates new student object
Student::Student(string fName, string lName, int id){
  m_fName = fName;
  m_lName = lName;
  m_id = id;
}


string Student::GetFName(){
  return m_fName;
}

string Student::GetLName(){
  return m_lName;
}

int Student::GetID(){
  return m_id;
}

void Student::SetFName(string fName){
  m_fName = fName;
}

void Student::SetLName(string lName){
  m_lName = lName;
}

void Student::SetID(int id){
  m_id = id;
}

// Name: Overloaded <<
// Description: Prints the details of a student
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of student
ostream& operator<< (ostream& line, Student& stud){
  //cout last name, first name, ID
  line << stud.m_lName << ", " << stud.m_fName << ", " << stud.m_id << endl;
  return line;
}

// Name: Overloaded <
// Description: Overloaded comparison operator (used for sorting)
// Preconditions: Two students being compared
// Postconditions: Returns m_lName first and then m_fName if m_lName same
bool operator< (const Student &s1, const Student &s2){
  //compare last names 1st
  if(s1.m_lName < s2.m_lName){
    //return true if s1 last name should come before s2 last name
    return true;
  }

  //if last names are equa, compare first names
  else if(s1.m_lName == s2.m_lName){
    //compare first names
    if(s1.m_fName < s2.m_fName){
      //return true if s1 first name should come before s2 first name
      return true;
    }

    //return false if s2 first name should come before s1 first name
    else{
      return false;
    }
  }

  //return false if s2 last name should come before s1 last name
  return false;
}
