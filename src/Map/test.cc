#include <map>
#include "s21_map.h"

int main() {
    s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (size_t i = 1; i < m2.size(); i++) {
        std::cout << m1.at(i) << " " << m2.at(i) << std::endl;
    }
// auto it = m1.begin();
// for (; it != m1.end(); it++) {
//     std::cout <<  (it)->second << std::endl;
// }
    return 0;
}