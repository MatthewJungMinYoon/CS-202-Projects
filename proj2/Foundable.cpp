/* Title: Foundable.cpp
   Author: Matthew Yoon
   Date: 10/1/2019
   Description: cpp file for Foundable
*/

#include "Foundable.h"
using namespace std;

Foundable::Foundable(){
  m_name = " ";
  m_type = " ";
  m_rarity = 0;
  m_toughness = 0;
}

Foundable::Foundable(string name, string type, int rarity, int toughness){
  m_name = name;
  m_type = type;
  m_rarity = rarity;
  m_toughness = toughness;
}

string Foundable::GetName(){
  return m_name;
}

string Foundable::GetType(){
  return m_type;
}

int Foundable::GetRarity(){
  return m_rarity;
}

int Foundable::GetToughness(){
  return m_toughness;
}

void Foundable::SetName(string newName){
  m_name = newName;
}

void Foundable::SetType(string newType){
  m_type = newType;
}

void Foundable::SetRarity(int newRarity){
  m_rarity = newRarity;
}

void Foundable::SetToughness(int newToughness){
  m_toughness = newToughness;
}
