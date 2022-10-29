#ifndef S21_LIST_H_
#define S21_LIST_H_
#include <initializer_list>
#include <stdexcept>
#include "iterator.h"
namespace s21 {
    template <typename T, class Alocator = std::allocator<T>>
            class List {
                using value_type = T;
                using pointer = T*;
                using reference = T&;
                using iterator = Iterator<T>;
                using node_pointer = Node<T>*;
                using node_type = Node<T>;
                using alloc_type = Alocator;
                using alloc_rebind = typename alloc_type::template rebind<Node<T>>::other;
                using size = std::size_t;
            private:
                node_pointer head_;
                node_pointer tail_;
                node_pointer iter_;
                size size_;
            public:
                List() : head_(nullptr), tail_(nullptr), iter_(new node_type), size_(0) {}
            };
}
#endif // S21_LIST_H_


