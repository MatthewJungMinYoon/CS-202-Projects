#include <iostream>
#include <string>
#include "Foundable.h" //Requires Foundable to be completed first
using namespace std;

//Constants
const int MIN_START_TOUGH = 150; //Minimum random starting toughness for wizard
const int MAX_START_TOUGH = 300; //Maximum random starting toughness for wizard
const int LEVEL_TOUGH_INCREASE = 100; //When wizard levels, max random increase

class Wizard{
 public:
  // Name: Wizard() Default Constructor
  // Preconditions: None
  // Postconditions: Creates new Wizard with valid values
  Wizard();
  // Name: Wizard() Overloaded Constructor
  // Preconditions: Requires valid name
  // Postconditions: Creates new Wizard with m_Toughness between 150 and 300
  //                 and m_Level = 1 with passed name
  Wizard(string name);
  // Name: GetName()
  // Preconditions: None
  // Postconditions: Returns m_name
  string GetName();
  // Name: GetToughness()
  // Preconditions: None
  // Postconditions: Returns m_toughness
  int GetToughness();
  // Name: GetLevel()
  // Preconditions: None
  // Postconditions: Returns m_level
  int GetLevel();
  // Name: GetWins()
  // Preconditions: None
  // Postconditions: Returns m_wins
  int GetWins();
  // Name: GetLosses()
  // Preconditions: None
  // Postconditions: Returns m_losses
  int GetLosses();
  // Name: SetName()
  // Preconditions: Requires valid string name
  // Postconditions: Updates m_name
  void SetName(string name);
  // Name: SetToughness()
  // Preconditions: Requires valid int toughness
  // Postconditions: Updates m_toughness
  void SetToughness(int toughness);
  // Name: InsertFoundable()
  // Preconditions: Requires a valid Foundable (from m_allFoundables)
  // Postconditions: Adds copy Foundable to m_foundables
  void InsertFoundable(Foundable newFoundable);
  // Name: CheckFoundable()
  // Preconditions: Requires valid Foundable
  // Postconditions: Returns true if exists in m_foundables else false
  bool CheckFoundable(Foundable newFoundable);
  // Name: AttackFoundable()
  // Preconditions: Requires valid enemy (Foundable pointer)
  // Postconditions: Compares Wizard toughness to the enemy toughness
  //                 (tie goes to enemy) Returns result of comparison
  bool AttackFoundable(Foundable enemy);
  // Name: PrintMyFoundables()
  // Preconditions: None
  // Postconditions: Displays a list of all foundables found by Wizard else indicates none found
  void PrintMyFoundables();
private:
  // Name: IncreaseLevel()
  // Preconditions: None
  // Postconditions: Updates m_level by one and increases toughness from 0 to 100
  void IncreaseLevel();
  string m_name; //Wizard name
  int m_toughness; //Wizard toughness
  int m_level; //Wizard level
  int m_wins; //Number of Wins
  int m_losses; //Number of Losses
  Foundable m_foundables [NUM_FOUNDABLE];
};

#endif
