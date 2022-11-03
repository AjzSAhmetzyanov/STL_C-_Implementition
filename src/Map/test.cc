#include <map>
#include "s21_map.h"

int main() {
    s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100,5},{4, 4}, {5, 5}};
    std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 5}, {4, 4}, {5, 5}};
    std::cout << m1.empty() <<" "<<m2.empty() << std::endl;
 std::cout << m1.insert_or_assign(3, 1).second << ""<< std::endl;
// for (; it != m1.end(); it++) {
//     std::cout <<  (it)->second << std::endl;
// }
    return 0;
}