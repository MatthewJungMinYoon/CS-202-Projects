/* Title: Game.cpp
   Author: Matthew Yoon
   Date: 10/3/2019
   Description: .cpp file for Game.h
*/


#include "Game.h"
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;

Game::Game(){
  MainMenu();
}

void Game::GetWizardName(){
  string name;
  cout << "What is your wizard's name? (press enter when done)" << endl;
  getline(cin, name, '\n');
  //  Wizard newWiz(name);

  m_wizard.SetName(name);
}

void Game::MainMenu(){
  LoadFoundables();
  GetWizardName();
  bool end = false;

  do{
    int choice;
    cout << "What would you like to do?" << endl;
    cout << "1. Wizard Information" << endl;
    cout << "2. List My Foundables" << endl;
    cout << "3. List All Foundables" << endl;
    cout << "4. Attack Foundables" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;

    //input validation
    while((choice < ONE) || (choice > FIVE)){
      cout << "Choice not valid" << endl;
      cin >> choice;
    }

    switch(choice){
    case ONE:
      WizardStat();
      break;
    case TWO:
      PrintMyFoundables();
      break;
    case THREE:
      PrintFoundables();
      break;
    case FOUR:
      AttackFoundable();
      break;
    case FIVE:
      end = true;
      break;
    default:
    cout << endl;
    }

    //win condition, if the wizard level = # of all foundables
    if(m_wizard.GetLevel() == (NUM_FOUNDABLE + 1)){
      end = true;
    }

  }while(end != true);
}

int Game::LoadFoundables(){
  ifstream myFile;
  myFile.open(FILE_NAME);

  string name;
  string type;
  string rarity;
  string toughness;

  int i = 0;
  if(myFile.is_open()){
    for(unsigned int i = 0; i < NUM_FOUNDABLE; i ++){
      getline(myFile, name, ',');
      getline(myFile, type, ',');
      getline(myFile, rarity, ',');
      getline(myFile, toughness, '\n');

      int intRare = stoi(rarity.c_str());
      int intTough = stoi(toughness.c_str());
      Foundable newFoundable(name, type, intRare, intTough);
      m_allFoundables[i] = newFoundable;
    }
  }
  myFile.close();
  return 0;
}

void Game::PrintFoundables(){
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    cout << i + 1 << "." << m_allFoundables[i].GetName() << " | " <<  m_allFoundables[i].GetType() << " | " <<  m_allFoundables[i].GetRarity() << " | " <<  m_allFoundables[i].GetToughness() << endl;
  }
}

void Game::WizardStat(){
  double wins = m_wizard.GetWins();
  double loss = m_wizard.GetLosses();
  double rate = (wins / (wins + loss)) * 100;

  cout << "Information About Wizard " << m_wizard.GetName() << endl;
  cout << "Level: " << m_wizard.GetLevel() << endl;
  cout << "Toughness: " << m_wizard.GetToughness() << endl;
  cout << "Foundables Found: " << m_wizard.GetLevel() - 1<< endl;
  cout << "Wins: " << m_wizard.GetWins() << " | Losses: " << m_wizard.GetLosses() << endl;
  if(wins == 0 && loss == 0){
    cout << "Win Rate: 0%" << endl;
  }
  else{
    cout << fixed << showpoint;
    cout.precision(2);
    cout << "Win Rate: " << rate << "%" << endl;
  }
}

void Game::PrintMyFoundables(){
  m_wizard.PrintMyFoundables();
}

void Game::AttackFoundable(){
  int chooseRare;
  cout << "What rarity of Foundable would you like to challenge (1-5)?" << endl;
  cin >> chooseRare;

  //input validation
  while((chooseRare < ONE) || (chooseRare > FIVE)){
    cout << "Must be between 1-5" << endl;
    cin >> chooseRare;
  }

  int check = 0;
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    if(m_allFoundables[i].GetRarity() == chooseRare){
      bool inMyFound = m_wizard.CheckFoundable(m_allFoundables[i]);
      if(inMyFound == false){
        check++;
      }
    }
  }

  if(check > 0){
    //choose a random index in bounds of m_allFoundables
    int randFound = rand()% (NUM_FOUNDABLE - 1) - 0;

    //choose another index if the rarities don't match
    while(chooseRare != m_allFoundables[randFound].GetRarity()){
      randFound = rand()% (NUM_FOUNDABLE - 1) - 0;
    }

    //attack the foundable
    cout << "The Wizard " << m_wizard.GetName() << " attacks " << m_allFoundables[randFound].GetName() << endl;

    bool wizardWon = m_wizard.AttackFoundable(m_allFoundables[randFound]);

    //if wizard won
    if(wizardWon == true){
      cout << "You defeated the " << m_allFoundables[randFound].GetName() << endl;
      m_wizard.InsertFoundable(m_allFoundables[randFound]);
    }

    //if wizard lost
    else{
    cout << "You do not successfully defeat the foundable" << endl;
    }
  }
  else{
    cout << "You have found all Foundables of that level of rarity!" << endl;
  }
}

