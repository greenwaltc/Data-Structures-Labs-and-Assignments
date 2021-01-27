#include <list>
using std::list;

void remove_divisible_by(list<int>& a_list, int div) {
  list<int>::iterator iter = a_list.begin();
  while (iter != a_list.end()) {
    if (*iter % div == 0)
      iter = a_list.erase(iter);
    else
      ++iter;
  }
}
