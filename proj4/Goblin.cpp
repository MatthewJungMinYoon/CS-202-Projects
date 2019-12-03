/* Title: Goblin.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Goblin.h
*/

#include "Goblin.h"
using namespace std;

// Name: Goblin() - Default Constructor
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin(){
}

// Name: Goblin(string name, int hp)
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin(string name, int hp):Monster(name,hp){
}

// Name: SpecialAttack
// Description: Defines the Goblin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Goblin::SpecialAttack(){
  int knaw = 2;
  cout << "The Goblin knaws at your ankles!" << endl;
  return knaw;
}
