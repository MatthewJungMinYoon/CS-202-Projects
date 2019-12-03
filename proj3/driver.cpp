#include "Decay.h"
#include "Node.h"
#include "DecayList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  srand(time(nullptr));

  Decay simulation;

  simulation.Start();

}
