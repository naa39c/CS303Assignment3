#include "lin_search.h"
#include <iostream>
#include <vector>

int main() {
  vector<int> items = {1, 2, 3, 4, 5, 2, 1, 3, 2};
  int target = 2;
  // set the target to 2, trying to find index of target
  size_t start_pos = 0;

  // calling lin_search for 2
  int last_occurrence = linear_search_last(items, target, start_pos);
  if (last_occurrence != -1) {
    cout << "Last occurrence of " << target
         << " is at index: " << last_occurrence << endl;
  } else {
    cout << target << " not found in the vector." << endl;
  }
//testing for 10 (OOB)
  target = 10;
  last_occurrence = linear_search_last(items, target, start_pos);
  if (last_occurrence != -1) {
    cout << "Last occurrence of " << target
         << " is at index: " << last_occurrence << endl;
  } else {
    cout << target << " not found in the vector." << endl;
  }
  //testing for 1
  target = 1;
  last_occurrence = linear_search_last(items, target, start_pos);
  if (last_occurrence != -1) {
    cout << "Last occurrence of " << target
         << " is at index: " << last_occurrence << endl;
  } else {
    cout << target << " not found in the vector." << endl;
  }
}