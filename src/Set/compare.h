#ifndef COMPARE_H_
#define COMPARE_H_
#include <utility>
namespace s21 {
    template <typename C>
    struct Compare {
        bool lt(const C &x, const C &y) const {  // less then
            return x < y;
        }
        bool gt(const C &x, const C &y) const {  // grater then
            return x > y;
        }
        bool le(const C &x, const C &y) const {  // less or equal
            return x <= y;
        }
        bool ge(const C &x, const C &y) const {  // grater or equal
            return x >= y;
        }
        bool eq(const C &x, const C &y) const {  // equal
            return x == y;
        }
        bool neq(const C &x, const C &y) const {  // not equal
            return x != y;
        }
    };

    template <class E, class F>
    struct Pair_compare {
        bool less(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first < y.first;
        }

        bool greater(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first > x.first;
        }

        bool less_or_equal(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first <= x.first;
        }

        bool greater_or_equal(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first >= x.first;
        }

        bool equal(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first == x.first;
        }

        bool no_equal(const std::pair<E, F> &x, const std::pair<E, F> &y) {
            return x.first != x.first;
        }
    };
}  // namespace s21
#endif  // COMPARE_H_