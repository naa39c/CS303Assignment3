#include <iostream>
using namespace std;
// linked node struct taken reference from lecture slide
struct Node {
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

void insertion_sort(Node *&head);
// PRE: head points to the head of a linked list
// POST: the linked list is sorted in ascending order

void print_list(Node *head);
// PRE: head points to the head of a linked list in ascending order
// POST: prints list

void append(Node *&head, int val);
// PRE: head points to the head of a linked list and value added
// POST: adds value to linked list

void insertion_sort(Node *&head) {
  if (!head || !head->next) {
    return; // if list is empty or has one element no need to sort
  }

  Node *sorted = nullptr; // start empty
  Node *current = head;

  while (current != nullptr) {
    Node *next = current->next; // saves next node
    if (!sorted || sorted->data >= current->data) {
      current->next = sorted;
      sorted = current;
    } else {
      Node *temp = sorted;
      while (temp->next != nullptr && temp->next->data < current->data) {
        temp = temp->next;
      }
      current->next = temp->next;
      temp->next = current;
    }
    current = next;
  }
  head = sorted; // head points to sorted list
}
// adds value to list
void append(Node *&head, int val) {
  Node *newNode = new Node(val);
  if (!head) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = newNode;
}
// prints list
void print_list(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
