#ifndef TQUEUE_CPP
#define TQUEUE_CPP

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: ClearData
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Empty m_data
  void ClearData();
  //Name: Enqueue
  //Desc: Adds item to the back of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue
  //NOTE: You may implement to only deal with dereferenced pointers
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (ascending)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****
template <class T, int N>
Tqueue<T,N>::Tqueue(){
  m_data = new T [N];
  m_front = 0;
  m_back = 0;
}

template <class T, int N>
Tqueue<T,N>::Tqueue(const Tqueue<T,N>& x ){
  m_data = new T [N];

  for(int i = 0; i < x.m_back - 1; i++){
    m_data[i] = x.m_data[i];
  }

  m_front = x.m_front;
  m_back = x.m_back;
}

template <class T, int N>
Tqueue<T,N>::~Tqueue(){
  ClearData();
}

template <class T, int N>
void Tqueue<T,N>::ClearData(){
  delete [] m_data;
  m_data = nullptr;
  m_back = 0;
}

template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){
  //if queue is empty
  if((m_back != N)){
    m_data[m_back] = data;
    m_back++;
  }

  //if queue has something in it
  else if(m_back >= N){
    cout << "not queued" << endl;
  }
}

template <class T, int N>
void Tqueue<T,N>::Dequeue(){
  //shift everything back one
  for(int i = 0; i < m_back - 1; i++){
    m_data[i] = m_data[i + 1];
  }

  m_back--;
}

template <class T, int N>
void Tqueue<T,N>::Sort(){
  T temp;
  //bubble sort
  for(int j = 0; j < m_back - 1; j++){
    for(int i = 0; i < m_back - 1; i++){
      if(*m_data[i+1] < *m_data[i]){
        temp = m_data[i];
        m_data[i] = m_data[i + 1];
        m_data[i + 1] = temp;
      }
    }
  }
}

template <class T, int N>
int Tqueue<T,N>::IsEmpty(){
  if(m_back == 0){
    return 1;
  }

  else{
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::IsFull(){
  if(m_back >= N){
    return 1;
  }

  else{
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::Size(){
  return m_back;
}

template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator= (Tqueue<T,N> y){
  ClearData();
  m_data = new T [N];

  for(int i = 0; i < y.m_back - 1; i++){
    m_data[i] = y.m_data[i];
  }

  m_front = y.m_front;
  m_back = y.m_back;

  return *this;
}

template <class T, int N>
T& Tqueue<T,N>::operator[] (int x){
  return m_data[x];
}
#endif
