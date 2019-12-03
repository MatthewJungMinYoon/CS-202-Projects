/* Title: Wizard.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Wizard.h
*/

#include "Wizard.h"
using namespace std;
// Name: Wizard() - Default Constructor
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(){
}

// Name: Wizard(string name, int hp)
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(string name, int hp):Character(name,hp){
}

// Name: ~Wizard - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Wizard::~Wizard(){
}

// Name: SpecialAttack
// Description: Defines the Wizard's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Wizard::SpecialAttack(){
  int max = 12;
  int min = 3;
  int special = rand() % max + min;
  cout << " casts magic missle!" << endl;
  return special;
}
