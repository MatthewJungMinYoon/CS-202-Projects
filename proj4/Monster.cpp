/* Title: Monster.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Monster.h
*/

#include "Monster.h"
using namespace std;

// Name: Monster() - Default Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster(){
}

// Name: Monster(string name, int hp) - Overloaded Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster(string name, int hp):Entity(name,hp){
}

// Name: Attack()
// Description: Describes attack statements for monster
// Preconditions: None
// Postconditions: Returns damage
int Monster::Attack(){
  int atk = 1;
  return atk;
}

// Name: SpecialAttack()
// Description: Purely virtual SpecialAttack
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
//virtual int SpecialAttack()=0;
