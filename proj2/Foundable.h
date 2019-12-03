#ifndef FOUNDABLE_H //Header Guard or Include Guard
#define FOUNDABLE_H //Header Guard (protects against multiple inclusion)

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Constants
const int NUM_FOUNDABLE = 192; //Number of Foundables

class Foundable{
 public:
  // Name: Foundable() (Default Constructor)
  // Desc: If a new Foundable is declared, it makes the values "valid"
  // Preconditions: None
  // Postconditions: Creates new Foundable with valid data
  Foundable();
  // Name: Foundable() (Overloaded Constructor)
  // Desc: Foundable with passed in values
  // Preconditions: Requires valid input data
  // Postconditions: Creates new Foundable with passed data
  Foundable(string name, string type, int rarity, int toughness);
  // Name: GetName()
  // Preconditions: None
  // Postconditions: Returns name
  string GetName();
  // Name: GetType()
  // Preconditions: None
  // Postconditions: Returns type (not currently used)
  string GetType();
  // Name: GetRarity()
  // Preconditions: None
  // Postconditions: Returns rarity
  int GetRarity();
  // Name: GetToughness()
  // Preconditions: None
  // Postconditions: Returns toughness
  int GetToughness();

  // Name: SetName()
  // Preconditions: Requires valid name
  // Postconditions: Updates value of m_name
  void SetName(string newName);
  // Name: SetType()
  // Preconditions: Requires valid type
  // Postconditions: Updates value of m_type
  void SetType(string newType);
  // Name: SetRarity()
  // Preconditions: Requires valid rarity (1-5)
  // Postconditions: Updates value of m_rarity
  void SetRarity(int newRarity);
  // Name: SetToughness()
  // Preconditions: Requires valid toughness
  // Postconditions: Updates value of m_toughness
  void SetToughness(int newToughness);

 private:
  string m_name; //Name of the Foundable
  string m_type; //Type of the Foundable
  int m_rarity; //Rarity of the Foundable (1-5)
  int m_toughness; //Toughness of the Foundable
};

#endif // Header Guard
