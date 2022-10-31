#include "s21_list.h"
#include <iostream>
#include <list>
int main() {
    s21::List<int> MyList_2 = {1, 534, 63, 123, 87, 123, 23, 9, 0};
    std::list<int> stdList = {1, 534, 63, 123, 87, 123, 23, 9, 0};
    MyList_2.sort();
    stdList.sort();
    auto it = MyList_2.begin();
    for (auto it_res = stdList.begin(); it_res != stdList.end(); it_res++) {
        std::cout << (*it) << " " << (*it_res) << std::endl;
        it++;
    }
    return 0;
}