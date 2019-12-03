#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node{
 public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Node();

  // Destructor
  // Preconditions: None
  // Postconditions: Frees dynamically allocated memory
  ~Node();

  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Initializes member variable with given argument
  Node(bool value);

  // ReplaceValue - Replaces m_value with opposite (if true then false or if false then true)
  // Preconditions: None
  // Postconditions: m_value negated
  void ReplaceValue();

  // SetNext() - Sets m_next
  // Preconditions: None
  // Postconditions: m_next is set
  void SetNext(Node* next);

  // GetNext() - returns m_next
  // Preconditions: None
  // Postconditions: returns m_next
  Node* GetNext();

  // GetValue() - returns m_value
  // Preconditions: None
  // Postconditions: returns m_value
  bool GetValue();

 private:
  Node* m_next; // Next Node in the list
  bool m_value; // Shows value of node (1 or 0)
};

#endif
