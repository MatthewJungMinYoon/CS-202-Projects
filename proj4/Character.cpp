/* Title: Character.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Character.h
*/

#include "Character.h"
#include <ctime>
using namespace std;

// Name: Character() - Default Constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can create a character
Character::Character(){
}

// Name: Character(string name, int hp) - Overloaded constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can be used to populate character or child classes
Character::Character(string name, int hp):Entity(name, hp){
}

// Name: ~Character - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Character::~Character(){
}

// Name: Attack()
// Description: Describes attack statements for character
// Preconditions: None
// Postconditions: Returns damage
int Character::Attack(){
  int max = 6;
  int min = 1;
  int attack = rand() % max + min;
  return attack;
}

// Name: SpecialAttack()
// Description: Tells player that character does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
int Character::SpecialAttack(){
  cout << " doesn't have a special attack" << endl;
  return 0;
}
