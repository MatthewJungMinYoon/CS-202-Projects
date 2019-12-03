/* Title: Wizard.cpp
   Author: Matthew Yoon
   Date: 10/1/2019
   Description: cpp file for Wizard.h
*/

#include "Wizard.h"
using namespace std;



Wizard::Wizard(){
  m_name = " ";
  m_toughness = rand()% MAX_START_TOUGH + MIN_START_TOUGH;
  m_level = 1;
  m_wins = 0;
  m_losses = 0;
}

Wizard::Wizard(string name){
  m_name = name;
  m_toughness = rand()% MAX_START_TOUGH + MIN_START_TOUGH;
  m_level = 1;
}

string Wizard::GetName(){
  return m_name;
}

int Wizard::GetToughness(){
  return m_toughness;
}

int Wizard::GetLevel(){
  return m_level;
}

int Wizard::GetWins(){
  return m_wins;
}

int Wizard::GetLosses(){
  return m_losses;
}

void Wizard::SetName(string name){
  m_name = name;
}

void Wizard::SetToughness(int toughness){
  m_toughness = toughness;
}

void Wizard::InsertFoundable(Foundable newFoundable){
  m_foundables[m_level - 1] = newFoundable;
  IncreaseLevel();
}

bool Wizard::CheckFoundable(Foundable newFoundable){
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    if((m_foundables[i].GetName() == newFoundable.GetName())){
      return true;
    }
  }
  return false;
}

bool Wizard::AttackFoundable(Foundable enemy){
  int result = m_toughness - enemy.GetToughness();
  if(result > 0){
    m_wins++;
    return true;
  }

  else{
    m_losses++;
    return false;
  }
}

void Wizard::PrintMyFoundables(){
  int i = 0;
  bool populated = false;
  while(i < NUM_FOUNDABLE && populated == false){
    if(m_foundables[i].GetName() != " "){
      populated = true;
    }
    else{
      i++;
    }
  }

  if(populated == true){
    for(int i = 0; i < NUM_FOUNDABLE; i++){
      if(m_foundables[i].GetName() == " "){
        return;
      }
      cout << i + 1 << "." << m_foundables[i].GetName() << " | " <<  m_foundables[i].GetType() << " | " <<  m_foundables[i].GetRarity() << " | " <<  m_foundables[i].GetToughness() << endl;
    }
  }
  else{
    cout << "You have not defeated any foundables yet." << endl;
  }
}


void Wizard::IncreaseLevel(){
  m_level++;
  int newTough = rand()% LEVEL_TOUGH_INCREASE + 0;
  m_toughness += newTough;
}
