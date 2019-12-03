/* Title: Node.cpp
   Author: Matthew Yoon
   Date: 10/14/2019
   Description: cpp file for Node.h
*/

#include "Node.h"
using namespace std;

// Constructor
// Preconditions: None
// Postconditions: None
Node::Node(){
}

// Destructor
// Preconditions: None
// Postconditions: Frees dynamically allocated memory
Node::~Node(){

}

// Overloaded Constructor
// Preconditions: None
// Postconditions: Initializes member variable with given argument
Node::Node(bool value){
  m_value = value;
}

// ReplaceValue - Replaces m_value with opposite (if true then false or if false then true)
// Preconditions: None
// Postconditions: m_value negated
void Node::ReplaceValue(){
  if(m_value == true){
    m_value = false;
  }

  else{
    m_value = true;
  }
}

// SetNext() - Sets m_next
// Preconditions: None
// Postconditions: m_next is set
void Node::SetNext(Node* next){
  m_next = next;
}

// GetNext() - returns m_next
// Preconditions: None
// Postconditions: returns m_next
Node* Node::GetNext(){
  return m_next;
}

// GetValue() - returns m_value
// Preconditions: None
// Postconditions: returns m_value
bool Node::GetValue(){
  return m_value;
}
