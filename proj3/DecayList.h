#ifndef DECAYLIST_H
#define DECAYLIST_H
#include <iostream>
#include "Node.h"
using namespace std;

const int NUM_CONSECUTIVE = 3;

class DecayList{
 public:
  // Constructor
  // Preconditions: None
  // Postconditions: New list is created
  DecayList();

  // Destructor
  // Preconditions: None
  // Postconditions: Dynamically allocated memory freed
  ~DecayList();

  // GetSize - Returns size of list
  // Preconditions: None
  // Postconditions: Returns size (as integer)
  int GetSize();

  // InvertValue - Chooses a node to replace value (with opposite value)
  // Preconditions: Node to be changed exists
  // Postconditions: Node's value is negated
  void InvertValue(int index);

  // PrintDecayList() - Prints the list of nodes and their values
  // Preconditions: None
  // Postconditions: m_value are printed out in order returns true if successfully prints
  bool PrintDecayList();

  // TraverseList - Loops list to see if any sequences of 3 or more nodes with a value of 1
  // Preconditions: DecayList has Nodes. Passed value to be checked (true by default)
  // Postconditions: Removes all sequences of nodess with 3 or more cards with a value of 1; returns number of cards removed
  int TraverseList(bool);

  // RemoveNodes - Called when 3 or more 1's in a row. Nodes are removed left to right.
  // Preconditions: A DecayList has a minimum of 3 nodes
  // Postconditions: The nodes are removed, which resizes DecayList; Returns number removed.
  int RemoveNodes(int, int);

  // CheckEmpty - Called to see if the list is empty
  // Preconditions: Nodes were removed from list
  // Postconditions: If empty, returns true and round ends
  bool CheckEmpty();

  // InsertEnd - Inserts new Node into end of DecayList
  // Preconditions: DecayList exists - may not create m_tail
  // Postconditions: Inserts passed node to end of list
  void InsertEnd(Node*);

 private:
  Node* m_head;
  int m_size;
};

#endif
