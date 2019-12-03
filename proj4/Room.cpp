/*Title: Room.cpp
  Author: Matthew Yoon
  Date: 11/6/2019
  Description: .cpp file for Room.h
*/

#include "Room.h"
using namespace std;

const int NEG_ONE = -1;
enum {ZERO, ONE, TWO, THREE, FOUR};

//Name: Room (Overloaded Constructor)
//Precondition: Must have valid input for each part of a room
//Postcondition: Creates a new room
Room::Room(int id, string name, string desc, int north, int east, int south, int west){
  m_ID = id;
  m_name = name;
  m_desc = desc;
  m_direction[0] = north;
  m_direction[ONE] = east;
  m_direction[TWO] = south;
  m_direction[THREE] = west;
}

//Name: GetName
//Precondition: Must have valid room
//Postcondition: Returns room name as string
string Room::GetName(){
  return m_name;
}

//Name: GetID
//Precondition: Must have valid room
//Postcondition: Returns room id as int
int Room::GetID(){
  return m_ID;
}

//Name: GetDesc
//Precondition: Must have valid room
//Postcondition: Returns room desc as string
string Room::GetDesc(){
  return m_desc;
}

//Name: CheckDirection
//Precondition: Must have valid room
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the room in that direction
//Postcondition: Returns id of room in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection){
  //if user chooses north
  if((myDirection == 'N') || (myDirection == 'n')){
    //return # if valid exit
    if(m_direction[0] != NEG_ONE){
      return m_direction[0];
    }

    else{
      return NEG_ONE;
    }
  }

  //if user chooses east
  if((myDirection == 'E') || (myDirection == 'e')){
    if(m_direction[ONE] != NEG_ONE){
      return m_direction[ONE];
    }

    else{
      return NEG_ONE;
    }
  }

  //if user chooses south
  if((myDirection == 'S') || (myDirection == 's')){
    if(m_direction[TWO] != NEG_ONE){
      return m_direction[TWO];
    }

    else{
      return NEG_ONE;
    }
  }

  //if user chooses west
  if((myDirection == 'W') || (myDirection == 'w')){
    if(m_direction[THREE] != NEG_ONE){
      return m_direction[THREE];
    }

    else{
      return NEG_ONE;
    }
  }
  return NEG_ONE;
}

void Room::PrintRoom(){
  cout << m_name << endl;
  cout << m_desc << endl;

  int index;
  char exit;
  for(int i = 0; i < FOUR; i++){
    if(m_direction[i] != NEG_ONE){
      index = i;
    }

    else if(index == 0){
    exit = 'N';
    }
    else if(index == ONE){
      exit = 'E';
    }
    else if(index == TWO){
    exit = 'S';
    }
    else if(index == THREE){
      exit = 'W';
    }
  }
  cout << "Possible Exits: " << exit << endl;
}
