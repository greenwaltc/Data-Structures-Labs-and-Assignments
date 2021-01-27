#include <string>
#include <list>
using std::list;
using std::string;

list<int>::iterator find(list<int>& a_list, int target)
{
  for (list<int>::iterator itr = a_list.begin();
       itr != a_list.end(); ++itr) {
    if (*itr == target)
      return itr;
  }
  return a_list.end();
}

list<string>::iterator find(list<string>& a_list, const string& target)
{
  for (list<string>::iterator itr = a_list.begin();
       itr != a_list.end(); ++itr) {
    if (*itr == target)
      return itr;
  }
  return a_list.end();
}


