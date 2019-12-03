/* Title: BabyDragon.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for BabyDragon.h
*/

#include "BabyDragon.h"
using namespace std;

// Name: BabyDragon() - Default Constructor
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon(){
}

// Name: Baby Dragon(string name, int hp)
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon(string name, int hp):Monster( name, hp){
}

// Name: SpecialAttack
// Description: Defines the Baby Dragon's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int BabyDragon::SpecialAttack(){
  int fire = 4;
  cout << "The baby dragon breathes a cone of fire at you!" << endl;
  return fire;
}
