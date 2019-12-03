#ifndef _ROGUE_H_
#define _ROGUE_H_

#include "Character.h"

class Rogue: public Character {
 public:
  // Name: Rogue() - Default Constructor
  // Description: Creates a new rogue
  // Preconditions: None
  // Postconditions: Can create a rogue
  Rogue();
  // Name: Rogue(string name, int hp)
  // Description: Creates a new rogue
  // Preconditions: None
  // Postconditions: Can create a rogue
  Rogue(string, int);
  // Name: ~Rogue - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Rogue();
  // Name: SpecialAttack
  // Description: Defines the Rogue's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
