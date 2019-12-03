/***********************************************************
 ** File:    Entity.h
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Nicholas Long and Jeremy Dixon
 ** Date     10/14/2019
 ** Section: N/A
 ** E-mail:  nlong2@umbc.edu
 ** This file contains the header file of the Entity class
 **********************************************************/
#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Entity {
 public:
  // Name: Entity() - Default Constructor
  // Description: Abstract class - cannot directly instantiate this class
  // Preconditions: None
  // Postconditions: Populates variables used in child classes (not specifically used)
  Entity();
  // Name: Entity(string, int) - Overloaded Constructor
  // Description: Abstract class - cannot directly instantiate this class
  // Preconditions: None
  // Postconditions: Populates variables used in child classes
  Entity(string, int);
  // Name: virtual ~Entity - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  virtual ~Entity();
  // Name: GetName()
  // Description: Returns name of entity
  // Preconditions: Entity has name
  // Postconditions: None
  string GetName();
  // Name: GetHealth()
  // Description: Returns health of entity
  // Preconditions: Entity has health
  // Postconditions: None
  int GetHealth();
  // Name: SetName()
  // Description: Sets name of entity
  // Preconditions: None
  // Postconditions: Name is set
  void SetName(string);
  // Name: SetHealth()
  // Description: Sets health of entity
  // Preconditions: None
  // Postconditions: Health is set
  void SetHealth(int);
  // Name: Attack()
  // Description: Defines attack for an entity
  // Preconditions: None
  // Postconditions: None (Purely virtual - must be in child classes)
  virtual int Attack() = 0;
  // Name: SpecialAttack()
  // Description: Defines special attack for an entity
  // Preconditions: None
  // Postconditions: None (Purely virtual - must be in child classes)
  virtual int SpecialAttack() = 0;
  // Name: Overloaded <<
  // Description: Prints the details of an entity
  // Preconditions: all variables are set valid
  // Postconditions: returns an ostream with output of entity
  friend ostream& operator<<(ostream&, Entity&);
private:
  string m_name; //Name of entity
  int m_health; //Health of entity
  int m_level; //Level of entity
};

#endif
