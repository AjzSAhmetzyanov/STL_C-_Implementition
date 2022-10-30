#include "s21_list.h"
#include <iostream>
#include <list>
int main() {
  s21::List<int> Mylist_1 = {1};
  Mylist_1.push_back(2);
  Mylist_1.push_back(3);
  Mylist_1.push_back(4);
   auto it1 = Mylist_1.begin();
    for (; it1 != Mylist_1.end(); it1++)
       std::cout << (*it1) << std::endl;
    return 0;
}