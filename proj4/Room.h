/*Title: Room.h
Author: Prof. Dixon
Date: 10/29/2019
Description: This class defines rooms in UMBC Adventure
*/
#ifndef ROOM_H //Header Guard
#define ROOM_H //Header Guard
#include <iostream>
#include <string>
using namespace std;

//Enum defining the directions in array n/N = 0, e/E = 1, s/S = 2, w/W = 3
enum direction{n=0,N=0,e=1,E=1,s=2,S=2,w=3,W=3};

class Room {
 public:
  //Name: Room (Overloaded Constructor)
  //Precondition: Must have valid input for each part of a room
  //Postcondition: Creates a new room
  Room(int, string, string, int, int, int, int);
  //Name: GetName
  //Precondition: Must have valid room
  //Postcondition: Returns room name as string
  string GetName();
  //Name: GetID
  //Precondition: Must have valid room
  //Postcondition: Returns room id as int
  int GetID();
  //Name: GetDesc
  //Precondition: Must have valid room
  //Postcondition: Returns room desc as string
  string GetDesc();
  //Name: CheckDirection
  //Precondition: Must have valid room
  //You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
  //returns the ID of the room in that direction
  //Postcondition: Returns id of room in that direction if the exit exists
  //If there is no exit in that direction, returns -1
  int CheckDirection(char myDirection);
  //Name: PrintRoom
  //Precondition: Room must be complete
  //Postcondition: Outputs the room name, room desc, then possible exits
  void PrintRoom();
 private:
  int m_ID; //Unique int for room number
  string m_name; //Name of room
  string m_desc; //Description of room
  int m_direction[4]; //Array holding room to north, east, south, west (-1 if no exit)
};
#endif //Header Guard
