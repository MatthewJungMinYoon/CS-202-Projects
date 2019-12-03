[matt45@linux4 proj1]cat proj1.cpp
/* File: Proj1.cpp
   Author: Matthew Yoon
   Date: 9/16/2019
   Section: 24
   Email: matt45@umbc.edu
   Description: Text based game where the user chases a rabbit on a 10x10 array grid.
*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//Constants
const int MAX_FIELD = 10; // Field size
const int MAX_POS = 9; // Max index for a position

const int FOUR = 4; // user choice 4
const int THREE = 3; // user choice 3
const int TWO = 2; // user choice 2
const int ONE = 1; //user choice 1

//Function Prototypes
int mainMenu(); // main menu
void startRab(char field[][MAX_FIELD]); // random rabbit start position
void startFarm(char field[][MAX_FIELD]); // user chooses farmaer start position
char moveRab(); // random rabbit movement
char moveFarm(); // user moves farmer
int findX(char field[][MAX_FIELD]); // finds the x coor
int findY(char field[][MAX_FIELD]); // finds the y coor
void makeField(char field[][MAX_FIELD]); // first making the field
void printField(char field[][MAX_FIELD]); //  displays entire field
void displayRab(int farmX, int farmY, int rabX, int rabY); // displays which direction the rabbit is in relation to the farmer

/* Name: startRab()
   Precondition: start of the program
   Post: randomly chooses the start position of the rabbit
*/
void startRab(char field[][MAX_FIELD]){
  int rabX;
  int rabY;

  //randomly chooses rabbit starting position
  srand(time(NULL));
  rabX = rand() % MAX_POS + 0;
  rabY = rand() % MAX_POS + 0;

  //places rabbit at starting position
  field[rabX][rabY] = 'R';
}

/* Name: startFarm()
   Precondition: start of the program
   Post: User chooses their start position
*/
void startFarm(char field[][MAX_FIELD]){
  int farmX;
  int farmY;
  //  char farmPos[MAX_FIELD][MAX_FIELD] = char field[MAX_FIELD][MAX_FIELD];

  cout << "Where would you like to start the farmer?" << endl;

  cout << "Enter the column(x) (0 - 9)" << endl;
  cin >> farmX;

  //input validation for x
  while(farmX < 0 || farmX > MAX_POS){
    cout << "Must be within the bounds" << endl;
    cin >> farmX;
  }

  cout << "Enter the row(y) (0 - 9)" << endl;
  cin >> farmY;

  //input validation for y
  while(farmY < 0 || farmY > MAX_POS){
    cout << "Must be within the bounds" << endl;
    cin >> farmY;
  }

  //places farmer in chosen starting locaiton
  field[farmX][farmY] = 'F';
}

/* Name: moveRab()
   Precondition: Rabbit is on the board
   Post: Rabbit moves
*/
void moveRab(char field[][MAX_FIELD], int rabX, int rabY){
  int newX = rabX;
  int newY = rabY;
  int newPos;
  // char rabPos[MAX_FIELD][MAX_FIELD] = field[MAX_FIELD][MAX_FIELD];

  srand(time(NULL));
  newPos = rand() % 4 + 1; // 1 = north, 2 = south, 3 = east, 4 = west

  //rabbit doesn't move if at the edge of the field
  while((newPos == ONE && rabX == 0) || (newPos == TWO && rabX == MAX_POS) || (newPos == THREE && rabY == MAX_POS) || (newPos == FOUR && rabY == 0)){
    return;
  }

  switch(newPos)
    {
      //North
    case ONE:
      newX -= 1;
      field[rabX][rabY] = ' '; //remove original "R"
      field[newX][newY] = 'R'; //place "R" in new position
      cout << "Rabbit moves north" << endl;
      break;

      //South
    case TWO:
      //rabbit moves down 1
      newX += 1;
      field[rabX][rabY] = ' ';
      field[newX][newY] = 'R';
      cout << "Rabbit moves south" << endl;
      break;

      //East
    case THREE:
      //rabbit moves right 1
      newY += 1;
      field[rabX][rabY] = ' ';
      field[newX][newY] = 'R';
      cout << "Rabbit moves east" << endl;
      break;

      //West
    case FOUR:
      //rabbit moves left 1
        newY -= 1;
        field[rabX][rabY] = ' ';
        field[newX][newY] = 'R';
        cout << "Rabbit moves west" << endl;
      break;

    default:
      cout << "" << endl;
    }
}

/* Name: moveFarm()
   Precondition: farmer is on board
   Post: user moves farmer
*/
void moveFarm(char field[][MAX_FIELD], int farmX, int farmY){
  int newX = farmX;
  int newY = farmY;
  int newPos;
  // char farmPos[MAX_FIELD][MAX_FIELD] = field[MAX_FIELD][MAX_FIELD];

  cout << "What would you like to do?" << endl;
  cout << "1. Search north." << endl;
  cout << "2. Search south." << endl;
  cout << "3. Search east." << endl;
  cout << "4. Search west." << endl;
  cin >> newPos;

  //input validation
  while(newPos < ONE || newPos > FOUR){
    cout << "Choice must be in bounds" << endl;
    cin >> newPos;
  }
  //if the user is at the edge of the field
  while((newPos == ONE && farmX == 0) || (newPos == TWO && farmX == MAX_POS) || (newPos == THREE && farmY == MAX_POS) || (newPos == FOUR && farmY == 0)){
    cout << "Farmer can't leave the field" << endl;
    cin >> newPos;
  }

  switch(newPos)
    {
      //north
    case ONE:
      newX -= 1;
      field[farmX][farmY] = ' '; //remove original "F"
      field[newX][newY] = 'F'; //put "F" in the chosen position
      cout << "Farmer moves north" << endl;
      break;

      //south
    case TWO:
      newX += 1;
      field[farmX][farmY] = ' ';
      field[newX][newY] = 'F';
      cout << "Farmer moves south" << endl;
      break;

      //east
    case THREE:
      newY += 1;
      field[farmX][farmY] = ' ';
      field[newX][newY] = 'F';
      cout << "Farmer moves east" << endl;
      break;

      //west
    case FOUR:
      newY -= 1;
      field[farmX][farmY] = ' ';
      field[newX][newY] = 'F';
      cout << "Farmer moves west" << endl;
      break;

    default:
      cout << "" << endl;
    }
}

/* Name: findX()
   Precondtion: farmer and rabbit are on the board
   Post: returns column number of either
*/
int findX(char field[][MAX_FIELD], char symbol){
  for(int i = 0; i < MAX_FIELD; i++){
    for(int j = 0; j < MAX_FIELD; j++){
      if(field[i][j] == symbol){
      return i;
      }
    }
  }
}

/* Name: findY()
   Precondition farmer and rabbit are on the board
   Post: returns row number of either
*/
int findY(char field[][MAX_FIELD], char symbol){
  for(int i = 0; i < MAX_FIELD; i++){
    for(int j = 0; j < MAX_FIELD; j++){
      if(field[i][j] == symbol){
      return j;
      }
    }
  }
}

/* Name: printField()
   Precondition: Program is running
   Post: Prints out the board.
*/
void printField(char field[][MAX_FIELD]){
  for(int i = 0; i < MAX_FIELD; i++){
    for(int j = 0; j < MAX_FIELD; j++){
      cout << "|" << field[i][j];
    }
    cout << "|";
    cout << endl;
  }
}

/* Name: makeField()
   Precondition: start of game
   Post: make empty field
*/
void makeField(char field[][MAX_FIELD]){
  for(int i = 0; i < MAX_FIELD; i++){
    for(int j = 0; j < MAX_FIELD; j++){
      field[i][j] = ' ';
    }
  }
}

/* Name: displayRab()
   Precondition: user hasn't found rabbit yet
   Post: outputs rabbit's direction
*/
void displayRab(int farmX, int farmY, int rabX, int rabY){
  if(rabX > farmX){
    cout << "The rabbit is south of the farmer" << endl;
  }
  if(rabX < farmX){
    cout << "The rabbit is north of the farmer" << endl;
  }
  if(rabY > farmY){
    cout << "The rabbit is east of the farmrer" << endl;
  }
  if(rabY < farmY){
    cout << "The rabbit is west of the farmer" << endl;
  }
}

int main(){
  char field[MAX_FIELD][MAX_FIELD];
  char playAgain;

  do{
    int farmX;
    int farmY;

    int rabX;
    int rabY;

    //make and print an empty board
    makeField(field);
    printField(field);

    //start of the game
    cout << "Welcome to Chase the Rabbit" << endl;

    //random start for the rabbit and gets X and Y locations
    startRab(field);
    rabX = findX(field, 'R');
    rabY = findY(field, 'R');

    //user chooses starting position, gets user X and Y locations
    startFarm(field);
    farmX = findX(field, 'F');
    farmY = findY(field, 'F');

    printField(field);
    do{

      //rabbit moves 1st, updates position
      moveRab(field, rabX, rabY);
      rabX = findX(field, 'R');
      rabY = findY(field, 'R');

      //user chooses where to go, updates position
      moveFarm(field, farmX, farmY);
      farmX = findX(field, 'F');
      farmY = findY(field, 'F');

      //tells where the rabbit is in relation to player position, prints out board
      displayRab(farmX, farmY, rabX, rabY);
      printField(field);

    }while((farmX != rabX) || (farmY != rabY)); //keep running until farmer and rabbit on the same position

    cout << "The farmer found the rabbit" << endl;
    cout << "Congrats you've won!" << endl;
    cout << "Play again? (y/n)" << endl;
    cin >> playAgain;

  }while(playAgain != 'n'); //if the user inputs "y" redo the game, if "n" end the program
}
