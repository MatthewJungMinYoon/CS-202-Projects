/* Title: Game.cpp
   Author: Matthew Yoon
   Date: 11/6/2019
   Description: .cpp file for Game.h
*/

#include "Game.h"
using namespace std;

const int NEG_ONE = -1;

enum{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX};

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: After asking for a file name, loads map, creates char and starts.
Game::Game(){
}

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Uses filesname to LoadMap, calls create character,
//                 and sets both numRests and m_numSpecial using constants.
Game::Game(string filename){
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;

  LoadMap(filename);
  CharacterCreation();
  StartGame();
}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game(){
  for(unsigned int i = 0; i < m_myMap.size(); i++){
    delete m_myMap.at(i);
    m_myMap.at(i) = nullptr;
  }
  delete m_myCharacter;
  delete m_curMonster;
  m_myCharacter = nullptr;
  m_curMonster = nullptr;
}

// Name: LoadMap(string fileName)
// Description: Dynamically creates rooms and inserts them into the m_myMap vector
// Precondition: File contains map information
// Postcondition: Map is populated with Room objects.
void Game::LoadMap(string fileName){
  ifstream myFile(fileName);

  string strID;
  string name;
  string desc;
  string strNorth;
  string strEast;
  string strSouth;
  string strWest;
  Room* newRoom;

  if(myFile.is_open()){
    while((getline(myFile, strID, '|'))){
      getline(myFile, name, '|');
      getline(myFile, desc, '|');
      getline(myFile, strNorth, '|');
      getline(myFile, strEast, '|');
      getline(myFile, strSouth, '|');
      getline(myFile, strWest, '|');

      int ID = atoi(strID.c_str());
      int north = atoi(strNorth.c_str());
      int east = atoi(strEast.c_str());
      int south = atoi(strSouth.c_str());
      int west = atoi(strWest.c_str());

      newRoom = new Room(ID, name, desc, north, east, south, west);
      m_myMap.push_back(newRoom);
    }
  }
}

// Name: CharacterCreation()
// Description: Allows user to create a new character (or child) to play with. May be either character, paladin, rogue, or wizard.
// Preconditions: None
// Postconditions: m_myCharacter is populated
void Game::CharacterCreation(){
  string name;
  int subClass;

  cout << "Character Name: ";
  cin >> name;
  cout << endl;

  cout << "Select a class" << endl;
  cout << "1. Rogue" << endl;
  cout << "2. Wizard" << endl;
  cout << "3. Paladin" << endl;
  cout << "4. No Class" << endl;
  cin >> subClass;

  //input validation
  while((subClass < ONE) || (subClass > FOUR)){
    cin >> subClass;
  }
  // different class options created
  if(subClass == ONE){
    m_myCharacter = new Rogue(name, ROGUE_HEALTH);
  }

  else if(subClass == TWO){
    m_myCharacter = new Wizard(name, WIZARD_HEALTH);
  }

  else if(subClass == THREE){
    m_myCharacter = new Paladin(name, PALADIN_HEALTH);
  }
  //if regular character is made
  else{
    m_myCharacter = new Character(name, WIZARD_HEALTH);
  }
}

// Name: StartGame()
// Description: After LoadMap and CharacterCreation, current room
//              is set (0 by default) and Action is called
// Preconditions: LoadMap and CharacterCreation must have been completed
// Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame(){
  m_curRoom = START_ROOM;
  Action();
}

// Name: Action()
// Description: Menu for game
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action(){
  int userInput;
  m_myMap.at(m_curRoom)->PrintRoom();
  m_curMonster = RandomMonster();

  //menu
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Monster" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> userInput;

    //input validation
    while((userInput < 1) || (userInput > 6)){
      cin >> userInput;
    }

    switch(userInput){

      //Look
    case ONE:
      //print the room
      m_myMap.at(m_curRoom)->PrintRoom();

      //if there is a monster
      if(m_curMonster != nullptr){
        if(m_curMonster->GetName() == "Baby Dragon"){
          cout << "A dragon is here" <<  endl;
        }
        else if(m_curMonster->GetName() == "Goblin"){
          cout << "A goblin is here picking his nose" << endl;
        }
        else if(m_curMonster->GetName() == "Skeleton"){
          cout << "A skeleton lumbers around the room" << endl;
        }
      }
      //if there isn't a monster
      else{
        cout << "It is peaceful here" << endl;
      }
      break;

      //Move
    case TWO:
      Move();
      break;

      //Attack
    case THREE:
      if(m_curMonster != nullptr){
        Attack();
      }
      else{
        cout << "There is no monster here" << endl;
      }
      break;

      //Rest
    case FOUR:
      //Can't rest is there is a monster
      if((m_curMonster != nullptr) && (m_curMonster->GetHealth() > 0)){
        cout << "You can't rest, there is a monster here" << endl;
      }

      //Can rest if there isn't a monster
      else{
        if(m_numRests > 0){
          m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
          m_numSpecial = NUM_SPECIAL;
          m_numRests--;
        }
        //Can't rest if out of rests
        else{
          cout << "You are out of rests" << endl;
        }
      }
      break;

      //Check Stats
    case FIVE:
      Stats();
      break;

    default:
      cout << "" << endl;
    }
  }while((userInput != SIX) && (m_myCharacter->GetHealth() > 0));

  //Quit
  if(userInput == SIX){
    cout << "Good bye!" << endl;
  }

  //lose condition
  if(m_myCharacter->GetHealth() == 0){
    cout << "You lose" << endl;
  }
}

// Name: RandomMonster()
// Description: Used to randomly create a dynamically allocated monster of Baby Dragon, Goblin, or Skeleton
// Preconditions: Has an entity pointer to hold monster child
// Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
Entity* Game::RandomMonster(){
  int newMon = rand() % FOUR + ONE;
  Entity* ranMon;

  switch(newMon){
  case ONE:
    ranMon = new BabyDragon("Baby Dragon", DRAGON_HEALTH);
    cout << "There is a baby dragon here" << endl;
    break;
  case TWO:
    ranMon = new Goblin("Goblin", GOBLIN_HEALTH);
    cout << "A goblin is here picking his nose" << endl;
    break;
  case THREE:
    ranMon = new Skeleton("Skeleton", SKELETON_HEALTH);
    cout << "A skeleton lumbers around the room" << endl;
    break;
  case FOUR:
    ranMon = nullptr;
    cout << "It is peaceful here" << endl;
    break;
  }
  return ranMon;
}

// Name: Move
// Description: Moves a player from one room to another (updates m_curRoom)
// Preconditions: Must be valid move (room must exist)
// Postconditions: Displays room information, checks for new monster (deletes old)
void Game::Move(){
  char moveDir;
  int newRoom;

  do{
    cout << "Which direction? (N E S W)" << endl;
    cin >> moveDir;

    //input validation
    while((moveDir != 'N') && (moveDir != 'E') && (moveDir != 'S') && (moveDir != 'W') && (moveDir != 'n') && (moveDir != 'e') && (moveDir != 's') && (moveDir != 'w')){
      cout << "Which direction? (N E S W)" << endl;
      cin >> moveDir;
    }

    //check if that direction has an exit
    newRoom = m_myMap.at(m_curRoom)->CheckDirection(moveDir);

  }while(newRoom == NEG_ONE);

  //if valid exit, update m_curRoom and generate random monster
  m_curRoom = newRoom;
  m_myMap.at(m_curRoom)->PrintRoom();
  m_curMonster = RandomMonster();
}

// Name: Attack
// Description: Allows player to attack an enemy entity.
// Preconditions: Must have enemy monster in room
// Postconditions: Indicates who wins and updates health(hp) as battle continues. May need to deallocate enemy monster to prevent memory leaks.
void Game::Attack(){
  int choose;
  int damage;
  int monsterAtk;
  int monsterDmg;

  while((m_myCharacter->GetHealth() > 0) && (m_curMonster->GetHealth() > 0)){
    cout << "1. Normal Attack" << endl;
    cout << "2. Special Attacks" <<  endl;
    cin >> choose;

    //input validation
    while((choose < ONE) && (choose > TWO)){
      cin >> choose;
    }

    //Normal Attack
    if(choose == ONE){
      damage = m_myCharacter->Attack();
    }

    //Special Attack
    else if (choose == TWO){

      //if user has specials
      if(m_numSpecial > 0){
        cout << m_myCharacter->GetName();
        damage = m_myCharacter->SpecialAttack();
        m_numSpecial = m_numSpecial - 1;
      }

      //if user is out of specials
      else if(m_numSpecial == 0){
        cout << "Out of special attacks" << endl;
      }
    }

    //randomly generate what type of attack monster will use
    monsterAtk = rand() % FOUR + ONE;

    //25% chance of it using special attack
    if(monsterAtk == ONE){
      monsterDmg = m_curMonster->SpecialAttack();
    }

    //rest is normal attack
    else{
      monsterDmg = m_curMonster->Attack();
    }

    //update player and monster health
    m_myCharacter->SetHealth(m_myCharacter->GetHealth() - monsterDmg);
    m_curMonster->SetHealth(m_curMonster->GetHealth() - damage);

    //print out damage player and monster do
    cout << m_myCharacter->GetName() << " attacks dealing " << damage << " damage" << endl;
    cout << m_curMonster->GetName() << " deals " << monsterDmg << " damage" << endl;

    //if health gets below 0, set to 0
    if(m_myCharacter->GetHealth() < 0){
      m_myCharacter->SetHealth(0);
    }
    //show updated health
    cout << m_myCharacter->GetName() << "'s health: " << m_myCharacter->GetHealth() << endl;

    //if monster health gets below 0
    if(m_curMonster->GetHealth() < 0){
      m_curMonster->SetHealth(0);
    }
    //show updated health
    cout << m_curMonster->GetName() << "'s health: " << m_curMonster->GetHealth() << endl;

  }
  if(m_curMonster->GetHealth() == 0){
   cout << "You have defeated the " << m_curMonster->GetName() << endl;
   //delete the monster
   delete m_curMonster;
   m_curMonster = nullptr;
  }
}

// Name: Stats()
// Description: Displays the information about the player (name, hp, rests, specials)
// Preconditions: None
// Postconditions: None
void Game::Stats(){
  cout << *m_myCharacter << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Specials: " << m_numSpecial << endl;
}
