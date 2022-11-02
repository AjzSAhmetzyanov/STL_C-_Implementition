//#include"rb_tree_node.h"
#include<iostream>
#include<vector>
#include<set>
#include "s21_set.h"
using namespace std;
int main() {
    std::set<double> s1 = {2,1,3,4,5,6,7,8,11,12};
    std::set<double> s2 = {2,1,3,4,5,6,7,8,9,10};
    std::cout << s1.size() << " " << s2.size() << std::endl;
  //s1.erase(s1.begin());
  //s2.erase(s2.begin());
  s1.merge(s2);
    //std::cout << s1.size() << " " << s2.size() << std::endl;
    auto it1 = s2.begin();
  //  auto it2 = s2.begin();
//    EXPECT_ANY_THROW(s1.erase(s1.end()));
    for (; it1 != s2.end(); it1++)
       std::cout << (*it1) << std::endl;
      //  std::cout << s1.size() << " " << s2.size() << std::endl;
//        std::cout << s11.size() << " " << s22.size() << std::endl;
    return 0;
}