/* Title: Decay.cpp
   Author: Matthew Yoon
   Date: 10/14/2019
   Description: cpp file for DecayList.h
*/

#include "DecayList.h"
using namespace std;

const int ONE = 1;
const int TWO = 2;
const int THREE = 3;

// Constructor
// Preconditions: None
// Postconditions: New list is created
DecayList::DecayList(){
  m_head = nullptr;
  m_size = 0;
}

// Destructor
// Preconditions: None
// Postconditions: Dynamically allocated memory freed
DecayList::~DecayList(){
  Node *temp = m_head;

  for(int i = 0; i < m_size; i++){
    m_head = temp->GetNext();
    delete temp;
    temp = nullptr;
    temp = m_head;
  }
}

// GetSize - Returns size of list
// Preconditions: None
// Postconditions: Returns size (as integer)
int DecayList::GetSize(){
  return m_size;
}

// InvertValue - Chooses a node to replace value (with opposite value)
// Preconditions: Node to be changed exists
// Postconditions: Node's value is negated
void DecayList::InvertValue(int index){
  Node *curr = m_head;

  for(int i = 0; i < (index - 1); i++){
    curr = curr->GetNext();
  }
  curr->ReplaceValue();
}

// PrintDecayList() - Prints the list of nodes and their values
// Preconditions: None
// Postconditions: m_value are printed out in order returns true if successfully prints
bool DecayList::PrintDecayList(){
  Node *curr = m_head;
  bool empty = CheckEmpty();

  if(empty == false){
    cout << endl;
    while(curr != nullptr){
      cout << "|" << curr->GetValue() << "|->";
      curr = curr->GetNext();
    }
    cout << "END" << endl;
    return true;
  }

  else{
    return false;
  }
}

// TraverseList - Loops list to see if any sequences of 3 or more nodes with a value of 1
// Preconditions: DecayList has Nodes. Passed value to be checked (true by default)
// Postconditions: Removes all sequences of nodess with 3 or more cards with a value of 1; returns number of cards removed
int DecayList::TraverseList(bool print){
  Node *curr = m_head;

  int index = 0;
  int count = 0;
  int newSize;

  if(print == true){
    while(curr != nullptr){

      //if the value is true, increment count
      if(curr->GetValue() == true){
        count++;
      }

      //as soon as count is incremented once, index = i as the start of the 3 in a row
      if(count == ONE){
        index -= TWO;
      }

      //if false, start over
      else if(curr->GetValue() == false){
        count = 0;
      }

      curr = curr->GetNext();

      //once 3 trues in a row, call remove, returns # of nodes removed(3)
      if(count == THREE){
        newSize = RemoveNodes(index, THREE);
        //reset count to check if there are anymore 3 in a row
        count = 0;
        //reset index
        index = 0;
        curr = m_head;
        return newSize;
      }
      index++;
    }
  }
  return 0;
}

// RemoveNodes - Called when 3 or more 1's in a row. Nodes are removed left to right.
// Preconditions: A DecayList has a minimum of 3 nodes
// Postconditions: The nodes are removed, which resizes DecayList; Returns number removed.
int DecayList::RemoveNodes(int index, int numNodes){
  Node *curr = m_head;
  Node *after = m_head->GetNext();
  Node *after2 = after->GetNext();
  Node *before = nullptr;
  int numRemove = 3;

  //if curr is at start
  if(curr->GetValue() == true){
    if((after->GetValue() == true) && (after2->GetValue() == true)){

      before = after2->GetNext();
      m_head = before;
      delete curr;
      delete after;
      delete after2;
      curr = nullptr;
      after = nullptr;
      after2 = nullptr;
    }
  }

  //if curr is in the middle, also works if after2 is at the end
  else{
    //cout << "Remove" << endl;
    //cout << "Index" << index << endl;
    //cout << "B4: " << before->GetValue() << "curr: " << curr->GetValue() << "aft: " << after->GetValue() << "aft2: " << after2->GetValue() << endl;
    //get to where curr is at index
    for(int i = 0; i < index; i++){
      before = curr;
      curr = after;
      after = after2;
      after2 = after2->GetNext();
    }
    //set the node's next before curr to after2's next and remove curr, after and after2
    before->SetNext(after2->GetNext());
    delete curr;
    delete after;
    delete after2;
    curr = nullptr;
    after = nullptr;
    after2= nullptr;
  }

  //Min # of nodes that can be removed is 3
  cout << "3 nodes removed!" << endl;
  //subtracts # of nodes removed(3) from m_size
  m_size -= numRemove;
  return numNodes;
}

// CheckEmpty - Called to see if the list is empty
// Preconditions: Nodes were removed from list
// Postconditions: If empty, returns true and round ends
bool DecayList::CheckEmpty(){
  if(m_head == nullptr){
    return true;
  }
  else{
    return false;
  }
}

// InsertEnd - Inserts new Node into end of DecayList
// Preconditions: DecayList exists - may not create m_tail
// Postconditions: Inserts passed node to end of list
void DecayList::InsertEnd(Node* next){
  Node *curr = m_head;

  if(CheckEmpty() == true){
    m_head = next;
    m_head->SetNext(nullptr);
  }

  else{
    while(curr->GetNext() != nullptr){
      curr = curr->GetNext();
    }
    curr->SetNext(next);
    next->SetNext(nullptr);
  }
  m_size++;
}
