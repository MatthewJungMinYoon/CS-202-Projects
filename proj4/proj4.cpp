#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a room file to be loaded." << endl;
    cout << "Usage: ./proj2 map2_data.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string mapName = argv[1];
  srand (time(NULL));
  Game g(mapName);
  return 0;
}
