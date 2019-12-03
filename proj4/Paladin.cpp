/* Title: Paladin.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Paladin.h
*/

#include "Paladin.h"
using namespace std;

// Name: Paladin() - Default Constructor
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin(){
}

// Name: Paladin(string name, int hp)
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin(string name, int hp):Character(name,hp){
}

// Name: ~Paladin - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Paladin::~Paladin(){
}

// Name: SpecialAttack
// Description: Defines the Paladin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Paladin::SpecialAttack(){
  int max = 8;
  int min = 1;
  int special = rand() % max + min;
  cout << " uses smite evil!" << endl;
  return special;
}
