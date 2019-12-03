#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Entity.h"

class Monster: public Entity {
 public:
  // Name: Monster() - Default Constructor
  // Description: Would be used to create a monster but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Monster();
  // Name: Monster(string name, int hp) - Overloaded Constructor
  // Description: Would be used to create a monster but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Monster(string, int);
  // Name: Attack()
  // Description: Describes attack statements for monster
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack()=0;
};
#endif
