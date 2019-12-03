/* Title: Decay.cpp
   Author: Matthew Yoon
   Date: 1014/2019
   Description: cpp file for Decay.h
*/

#include "Decay.h"
using namespace std;

const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int TEN_THOU = 10000;

// Constructor
// Preconditions: None
// Postconditions: None
Decay::Decay(){
}

// Destructor - Deletes all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleted and there are no memory leaks
Decay::~Decay(){
  EmptyLists();
}

// EmptyLists() - Empties all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleated and there are no memory leaks
void Decay::EmptyLists(){
  for(unsigned int i = 0; i < m_list.size(); i++){
    delete m_list.at(i);
    m_list.at(i) = nullptr;
  }
}


// LoadFile - Requests a file and loads all linked lists in a file (separated by ;)
// Preconditions: Valid input file exists (preferably with three lines of data)
// Postconditions: m_list is initialized
void Decay::LoadFile(){
  cout << "What is the name of the file?" << endl;
  cin >> m_file;

  ifstream myFile(m_file);

  char temp;
  Node *newNode = new Node(false);
  DecayList *newList = new DecayList();

  if(myFile.is_open()){
    while(myFile >> temp){

      if(temp == '0'){
        newNode = new Node(false);
        newList->InsertEnd(newNode);
      }

      if(temp == '1'){
        newNode = new Node(true);
        newList->InsertEnd(newNode);
      }

      if(temp == ';'){
        m_list.push_back(newList);
        newList = new DecayList();
      }
    }
  }
  myFile.close();
  delete newList;
}


// ChooseList - After a file is loaded, allows user to choose a list to simulate
// Preconditions: User has chosen to start simulation
// Postconditions: Simulation is started on list chosen by user
void Decay::ChooseList(){
  int userInput;
  do{
    cout << "Which Decay sceneario do you want to experience?" << endl;

    for(unsigned int i = 0; i < m_list.size(); i++){
      cout << "List " << i+1 << "(" << m_list[i]->GetSize() << " nodes)" << endl;
    }

    cin >> userInput;
  }while((userInput < ONE) || (userInput > static_cast<int>(m_list.size())));
  RunSimulation(userInput - 1);
}


// CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each
// Preconditions: m_list is empty
// Postconditions: m_list.at(0) has a list loaded into it
void Decay::CreateRandomList(){
  int userSize;
  int newSize;
  DecayList *newRanList = new DecayList();
  Node *newRanNode = new Node(false);

  cout << "How large a list would you like? " << endl;
  cin >> userSize;

  //input validation
  while((userSize < ONE) || (userSize > TEN_THOU)){
    cout << "Invalid input" << endl;
    cin >> userSize;
  }

  //user input * 3
  newSize = userSize * 3;

  //newRanList = new DecayList();

  //create x*3 many nodes with random values and create a new linked list
  for(int i = 0; i < newSize; i++){
    int random = rand()% 2;
    if(random == 1){
      newRanNode = new Node(true);
    }
    else if(random == 0){
      newRanNode = new Node(false);
    }
    newRanList->InsertEnd(newRanNode);
  }
  //pushback into vector of linked lists
  m_list.push_back(newRanList);
  RunSimulation(m_list.size() - 1);
}


// RunSimulation - Simulate one of the loaded lists
// Preconditions: A DecayList is available
// Postconditions: Simulation is run
void Decay:: RunSimulation(int index){
  bool print = true;
  int userInput;
  int nodesRemoved;

  while(print == true){
    print = m_list[index]->PrintDecayList();

    cout << "Which node to change?" << endl;

    //input validation if user input is out of list's bounds
    do{
      //print out each node's position
      for(int i = 0; i < m_list[index]->GetSize(); i++){
        cout << "  " << i + 1 << "  ";
      }
      cout << endl;
      cin >> userInput;

    }while((userInput < 1) || (userInput > m_list[index]->GetSize()));

    //change chosen node's value
    m_list[index]->InvertValue(userInput);

    //check if theres 3 or more in a row to remove
    nodesRemoved = m_list[index]->TraverseList(print);

    if(nodesRemoved == THREE){
      cout << "Nodes successfully removed" << endl;
    }

    //when all nodes in the linked list are removed
    if(m_list[index]->CheckEmpty() == true){
      cout << "All nodes from that list have been removed!" << endl;
      print = false;
    }
  }
}


// Start - Starts sim. Can load file, choose list, or create random list
// Preconditions: A DecayList is available
// Postconditions: Empties all lists after one is simulated.
void Decay::Start(){
  int userInput;
  int allClear;

  cout << "Welcome to Decay , where you code" << endl;

  do{
    cout << "1. Load File" << endl;
    cout << "2. Simulate Loaded File" << endl;
    cout << "3. Simulate Random List" << endl;
    cout << "4. Quit" << endl;
    cin >> userInput;

    while((userInput < ONE) || (userInput > FOUR)){
      cout << "Invalid" << endl;
      cin >> userInput;
    }

    switch(userInput)
      {
      case ONE:
        LoadFile();
        break;
      case TWO:
        ChooseList();
        break;
      case THREE:
        CreateRandomList();
        break;
      default:
        cout << endl;
      }

    //iterate through vector to see if all linked lists are empty
    for(unsigned int i = 0; i < m_list.size(); i++){
      if(m_list[i]->CheckEmpty() == true){
        allClear ++;
      }
    }
    //if all linked lists are empty print out that they are
    if(allClear == static_cast<int>(m_list.size())){
      cout << "All lists have been cleared." << endl;
    }

  }while(userInput != FOUR);
}

