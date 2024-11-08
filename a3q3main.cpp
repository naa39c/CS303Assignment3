#include "insert_sort.h"
#include <iostream>
int main() {
  Node *head = nullptr;
  
  // appending vals to linked list
  append(head, 99);
  append(head, 88);
  append(head, 23);
  append(head, 42);
  append(head, 3);
  append(head, 52);

  cout << "Pre-sorted list: ";
  print_list(head);

  // sort linked list
  insertion_sort(head);

  cout << "Post-Sorted list: ";
  print_list(head);
}
