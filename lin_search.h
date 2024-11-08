#include <vector>
using namespace std;
template <typename Item_Type>
int linear_search_last(const vector<Item_Type> &items, const Item_Type &target,
                       size_t pos_first) {
  // base case: returning -1 we've gone through the rest
  if (pos_first == items.size())
    return -1;

  // recursive: keep going through
  int result = linear_search_last(items, target, pos_first + 1);

  // if  target  found , return the index
  // if result == -1, we are at the current position with a match
  if (result != -1)
    return result;

  // if target matches pos
  if (items[pos_first] == target)
    return pos_first;

  // if not found, return -1
  return -1;
}
