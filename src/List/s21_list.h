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
                using const_reference = const T&;
                using iterator = Iterator<T>;
                using node_pointer = Node<T>*;
                using node_type = Node<T>;
                using alloc_type = Alocator;
                using alloc_rebind = typename alloc_type::template rebind<Node<T>>::other;
                using size_type = std::size_t;
            private:
                node_pointer head_;
                node_pointer tail_;
                node_pointer iter_;
                size_type size_;
            public:
                List() : head_(nullptr), tail_(nullptr), iter_(new node_type), size_(0) {}
                List(size_type n) : List() {
                    for (size_type i = 0; i < n; i++) {
                        this->push_back(value_type());
                    }
                }
                List(std::initializer_list<value_type> const &items) : List() {
                    for (auto it = items.begin(); it != items.end(); it++)
                        this->push_back(*it);
                }
                List(const List &other) : List() {
                    this->copy(other);
                }
                List(List &&other) : List() {
                    other.clear();
                }
                ~List() {
                    this->clear();
                    delete iter_;
                }

                List& operator=(const List &other) {
                    this->copy(other);
                    return *this;
                }
                void begin() {
                    if (this->head_ != nullptr) return this->head_;
                    else return this->iter_;
                }
                void begin() const{
                    if (this->head_ != nullptr) return this->head_;
                    else return this->iter_;
                }
                void end() {
                    return this->iter_;
                }
                void end() const{
                    return this->iter_;
                }
                const_reference front() {
                    return (this->head_ != nullptr) ? this->head_->data : this->iter_->data;
                }
                const_reference back() {
                    return (this->tail_ != nullptr) ? this->tail_->data : this->iter_->data;
                }
                void copy(const List &other) {
                    this->clear();
                    if (other.size_ != 0) {
                        for (auto iter = other.begin(); iter != other.end(); ++iter) {
                            this->push_back(*iter);
                        }
                    }
                }
                void clear() {
                    size_type const_size = this->size_;
                    for (size_type i = 0; i < const_size; i++)
                        this->erase(this->begin());
                }
                void pop_back() {
                    if (this->empty())
                        throw std::out_of_range("List is empty");
                    this->erase(--end());
                }
                void pop_front() {
                    if (this->empty())
                        throw std::out_of_range("List is empty");
                    this->erase(begin());
                }
                void push_back(const_reference value) {
                    node_pointer temp = (value, nullptr, this->tail_); //fix
                    if (this->tail_ != nullptr)
                        this->tail_->next = temp;
                    if (this->size_ == 0)
                        this->head_ = this->tail_ = temp;
                    else
                        this->tail_ = temp;
                    this->size_++;
                    this->set_iter(this->size_);
                }
                void push_front(const_reference value) {
                    node_pointer temp = new Node(value, this->head_, nullptr);
                    if (this->head_ != nullptr)
                        this->head_-> back = temp;
                    if (this->size_ == 0)
                        this->head_ = this->tail_ = temp;
                    else
                        this->head_ = temp;
                    this->size_++;
                    this->set_iter(this->size_);
                }
                void set_iter(const_reference value) {
                    if (this->head_ != nullptr && this->tail_ != nullptr) {
                        this->head_->back = this->iter_;
                        this->tail_->next = this->iter_;
                    }
                    this->iter_->back = this->tail_;
                    this->iter_->next = this->head_;
                    this->iter_->data = value;
                }
                bool empty() {
                    return (this->size_ == 0);
                }
                size_type size() {
                    return this->size_;
                }
                size_type max_size() {

                }


            };
}
#endif // S21_LIST_H_


