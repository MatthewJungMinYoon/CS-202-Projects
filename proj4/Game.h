#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Room.h"
#include "Entity.h"
#include "Monster.h"
#include "Character.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "BabyDragon.h"
#include "Rogue.h"
#include "Wizard.h"
#include "Paladin.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
const int ROGUE_HEALTH = 12; //starting health for rogue
const int WIZARD_HEALTH = 10;  //starting health for wizard
const int PALADIN_HEALTH = 15; //starting health for paladin
const int GOBLIN_HEALTH = 5; //starting health for goblin
const int SKELETON_HEALTH = 7; //starting health for skeleton
const int DRAGON_HEALTH = 10; //starting health for dragon
const int NUM_RESTS = 1; //starting rests for player
const int NUM_SPECIAL = 3; //starting special attacks for player
const int REST_HEAL = 10; //how much health is restored from rest
const int START_ROOM = 0; //starting room number
//******************************************************

class Game {
public:
  // Name: Game() - Default Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: After asking for a file name, loads map, creates char and starts.
  Game();
  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Uses filesname to LoadMap, calls create character,
  //                 and sets both numRests and m_numSpecial using constants.
  Game(string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated in Game
  ~Game();
  // Name: LoadMap(string fileName)
  // Description: Dynamically creates rooms and inserts them into the m_myMap vector
  // Precondition: File contains map information
  // Postcondition: Map is populated with Room objects.
  void LoadMap(string);
  // Name: CharacterCreation()
  // Description: Allows user to create a new character (or child) to play with. May
  //              be either character, paladin, rogue, or wizard.
  // Preconditions: None
  // Postconditions: m_myCharacter is populated
  void CharacterCreation();
  // Name: StartGame()
  // Description: After LoadMap and CharacterCreation, current room
  //              is set (0 by default) and Action is called
  // Preconditions: LoadMap and CharacterCreation must have been completed
  // Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
  void StartGame();
  // Name: Action()
  // Description: Menu for game
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Action();
  // Name: RandomMonster()
  // Description: Used to randomly create a dynamically allocated monster
  //              of Baby Dragon, Goblin, or Skeleton
  // Preconditions: Has an entity pointer to hold monster child
  // Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
  Entity* RandomMonster();
  // Name: Move
  // Description: Moves a player from one room to another (updates m_curRoom)
  // Preconditions: Must be valid move (room must exist)
  // Postconditions: Displays room information, checks for new monster (deletes old)
  void Move();
  // Name: Attack
  // Description: Allows player to attack an enemy entity.
  // Preconditions: Must have enemy monster in room
  // Postconditions: Indicates who wins and updates health(hp) as battle continues.
  //                 May need to deallocate enemy monster to prevent memory leaks.
  void Attack();
  // Name: Stats()
  // Description: Displays the information about the player (name, hp, rests, specials)
  // Preconditions: None
  // Postconditions: None
  void Stats();
private:
  vector<Room*> m_myMap; // Vector for holding all rooms in game
  Entity* m_myCharacter; // Entity pointer for player (or paladin, rogue or wizard)
  int m_curRoom; // Current room that player is in
  Entity* m_curMonster; // Current monster loaded for current room
  int m_numRests; // Number of rests for player
  int m_numSpecial; // Number of special attacks for player (refreshed after rests)
};

#endif
