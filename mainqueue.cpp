#include "queue.h"

int main() {
  Queue<int> q;

  // pushing numbers 0-10
  for (int i = 0; i <= 10; ++i) {
    q.push(i);
  }

  // show elemns in queue
  cout << "Queue: ";
  q.display();
  q.front();
  // moves front to rear
  cout << "After moving the front element to rear: ";
  q.move_to_rear();
  q.display();
  cout << "Size: " << q.size() << endl;

  cout << "New front: " << q.front() << endl;
  cout << "Is empty? 1 for yes, 0 for no: " << q.empty() << endl;
  cout << "new queue:";
  q.display();
  q.pop();
  cout << "After popping front: ";
  q.display();
  cout << "Size: " << q.size() << endl;
  cout << "Emptying queue." << endl;
  for (int i = 0; i <= 9; ++i) {
    q.pop();
  }
  cout << "Is empty? 1 for yes, 0 for no: " << q.empty() << endl;
}