#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Entity.h"

class Character: public Entity {
 public:
  // Name: Character() - Default Constructor
  // Description: Creates a new character
  // Preconditions: None
  // Postconditions: Can create a character
  Character();
  // Name: Character(string name, int hp) - Overloaded constructor
  // Description: Creates a new character
  // Preconditions: None
  // Postconditions: Can be used to populate character or child classes
  Character(string, int);
  // Name: ~Character - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Character();
  // Name: Attack()
  // Description: Describes attack statements for character
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Tells player that character does not have special attack
  // may be used for child class special attacks
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack();
};
#endif
