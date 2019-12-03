#include "Scheduler.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a roster file to be loaded." << endl;
    cout << "Usage: ./proj5 proj5_test1.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string rosterFile = argv[1];
  Scheduler s(rosterFile);
  s.Start();
  return 0;
}
