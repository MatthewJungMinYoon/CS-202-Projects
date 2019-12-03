/* Title: Skeleton.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Skeleton.h
*/

#include "Skeleton.h"
using namespace std;

// Name: Skeleton() - Default Constructor
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton(){
}

// Name: Skeleton(string name, int hp)
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton(string name, int hp):Monster(name, hp){
}

// Name: SpecialAttack
// Description: Defines the Skeleton's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Skeleton::SpecialAttack(){
  int bash = 1;
  cout << "The skeleton bashes you with its own arm!" << endl;
  return bash;
}
