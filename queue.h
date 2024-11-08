#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T> class Queue {
private:
  struct Node {
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
  };
  Node *frontNode; // points to the front
  Node *rearNode;  // points to the rear
  int queueSize;   // size of queue
public:
  Queue();
  // default constructor
  ~Queue();
  // deconstructor

  void push(const T &value);
  // PRE: Value to push to queue
  // POST: Adds value to queue
  void pop();
  // PRE: None
  // POST: pops item from queue
  T &front();
  // PRE: None
  // POST: gives front element
  int size() const;
  // PRE: None
  // POST: gives size
  bool empty() const;
  // PRE: None
  // POST: checks if empty
  void move_to_rear();
  // PRE: None
  // POST: moves front element to back
  void display();
  // PRE: None
  // POST: displays all queue elements
};
// default
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// destructor
template <typename T> Queue<T>::~Queue() {
  while (!empty()) {
    pop();
  }
}

// element to end of queue
template <typename T> void Queue<T>::push(const T &value) {
  Node *newNode = new Node(value);
  if (empty()) {
    frontNode = rearNode = newNode;
  } else {
    rearNode->next = newNode;
    rearNode = newNode;
  }
  ++queueSize;
}

// gets rid of front eleme
template <typename T> void Queue<T>::pop() {
  if (empty()) {
    cerr << "Queue is empty. Cannot pop.\n";
    return;
  }
  Node *temp = frontNode;
  frontNode = frontNode->next;
  delete temp;
  --queueSize;
  if (queueSize == 0) {
    rearNode = nullptr;
  }
}

// gives back front
template <typename T> T &Queue<T>::front() {
  if (empty()) {
    throw runtime_error("Queue is empty. No front element.");
  }
  return frontNode->data;
}

// declarations
template <typename T> int Queue<T>::size() const { return queueSize; }
template <typename T> bool Queue<T>::empty() const { return queueSize == 0; }
template <typename T> void Queue<T>::move_to_rear() {
  // move to rear
  if (empty() || queueSize == 1) {
    return; // cant move if equal or less than 1
  }
  T frontElement = front();
  // save front, pop it, and move it to back
  pop();
  push(frontElement);
}

// display elems in the queue
template <typename T> void Queue<T>::display() {
  int n = size();
  for (int i = 0; i < n; ++i) {
    cout << front() << " ";
    move_to_rear();
  }
  cout << "\n";
}