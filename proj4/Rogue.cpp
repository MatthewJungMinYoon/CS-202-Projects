/* Title: Rogue.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Rogue.h
*/

#include "Rogue.h"
using namespace std;

// Name: Rogue() - Default Constructor
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue(){
}

// Name: Rogue(string name, int hp)
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue(string name, int hp):Character(name,hp){
}

// Name: ~Rogue - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Rogue::~Rogue(){
}

// Name: SpecialAttack
// Description: Defines the Rogue's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Rogue::SpecialAttack(){
  int max = 12;
  int min = 2;
  int special = rand() % max + min;
  cout << " performs a sneak attack!" << endl;
  return special;
}
