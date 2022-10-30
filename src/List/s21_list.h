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
                using const_iterator = ConstIterator<T>;
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

            protected:
                alloc_rebind alloc_;
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
                iterator begin() {
                    return (this->head_ != nullptr) ? this->head_ : this->iter_;
                }
                iterator begin() const{
                    return (this->head_ != nullptr) ? this->head_ : this->iter_;
                }
                iterator end() {
                    return this->iter_;
                }
                iterator end() const{
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
                    node_pointer temp = new node_type(value, nullptr, this->tail_); //fix
                    if (this->tail_ != nullptr)
                        this->tail_->next_ = temp;
                    if (this->size_ == 0)
                        this->head_ = this->tail_ = temp;
                    else
                        this->tail_ = temp;
                    this->size_++;
                    this->set_iter(this->size_);
                }
                void push_front(const_reference value) {
                    node_pointer temp = new node_type(value, this->head_, nullptr);
                    if (this->head_ != nullptr)
                        this->head_->prev_ = temp;
                    if (this->size_ == 0)
                        this->head_ = this->tail_ = temp;
                    else
                        this->head_ = temp;
                    this->size_++;
                    this->set_iter(this->size_);
                }
                void set_iter(const_reference value) {
                    if (this->head_ != nullptr && this->tail_ != nullptr) {
                        this->head_->prev_ = this->iter_;
                        this->tail_->next_ = this->iter_;
                    }
                    this->iter_->prev_ = this->tail_;
                    this->iter_->next_ = this->head_;
                    this->iter_->data_ = value;
                }
                bool empty() {
                    return (this->size_ == 0);
                }
                size_type size() {
                    return this->size_;
                }
                size_type max_size() {
                    return alloc_.max_size();
                }
                iterator insert(iterator pos, const_reference value) {
                    iterator res;
                    if (pos == begin()) {
                        push_front(value);
                        res = begin();
                    } else if (pos == end()) {
                        push_back(value);
                        res = tail_->prev_;
                    } else {
                        node_pointer node_for_pos = new node_type {value, this->head_, nullptr};
                        if (pos.node()->prev_) {
                            pos.node()->prev_->next_ = node_for_pos;
                            node_for_pos->prev_ = pos.node()->prev_;
                        }
                        pos.node()->prev_ = node_for_pos;
                        node_for_pos->next_ = pos.node();
                        size_++;
                        res = iterator(node_for_pos);
                    }
                    return res;
                }
                void erase(iterator pos) {
                    if (pos == this->end() || this->empty())
                    throw std::out_of_range("Error: Iterator is out of range");
                    node_pointer node = this->get_node_by_pos(pos.node());
                    node_pointer node_next = node->next_;
                    node_pointer node_back = node->prev_;
                    if (this->size_ > 1 && node_next != this->iter_)
                      node_next->prev_ = node_back;
                    if (this->size_ > 1 && node_back != this->iter_)
                         node_back->next_ = node_next;
                    if (pos == this->begin())
                         this->head_ = node_next;
                     if (pos == --end())
                      this->tail_ = node_back;
                     this->size_--;
                 this->set_iter((this->size_ == 0) ? value_type() : node->data_);
                  delete node;
                }
                void swap(List& other) {
                     List new_list(other);
                        other = *this;
                         *this = new_list;
                }
                void merge(List& other) {
                    iterator it_this = this->begin();
                     value_type prev_value = other.front();
                  for (auto it_other = other.begin(); it_other != other.end(); prev_value = *it_other) {
                       if (*it_other < prev_value || *it_this > *it_other) {
                            this->insert(it_this, *it_other);
                                ++it_other;
                       } else {
                           ++it_this;
                                        }
                    }
                  other.clear();
                }
void splice(const_iterator pos, List& other) {
    iterator this_it = this->begin();
    for (; this_it != pos; ++this_it) {;}
    for (auto it = other.begin(); it != other.end(); ++it)
        insert(this_it, *it);
    other.clear();
}
void reverse() {
    List reverse_list;
    for (auto it = this->begin(); it != this->end(); ++it)
        reverse_list.push_front(*it);
    *this = reverse_list;
}
void unique() {
    iterator it_next = ++(this->begin());
    for (auto it = this->begin(); it_next != this->end(); ++it_next) {
        if (*it == *it_next)
            this->erase(it_next);
        else
            ++it;
    }
}
                void sort() {
                    if (!this->empty()) {
                        head_ = sorting(head_);
                    }
                }
        node_pointer sorting(node_pointer head) {
                    if (head == tail_ || head->next() == tail_) {
            return head;
        }
        node_pointer mid = split_list(head);
        node_pointer a = head;
        node_pointer b = mid->next();
        mid->next() = tail_;

        a = sorting(a);
        b = sorting(b);
        return merge(a, b);
        }

    node_pointer split_list(node_pointer head) {
        node_pointer fast = head->next();
        node_pointer slow = head;

        while (fast != tail_ && fast->next() != tail_) {
            fast = fast->next()->next();
            slow = slow->next();
        }
        return slow;
    }

node_pointer get_node_by_pos(const_iterator pos) {
    node_pointer result = head_;
    for (auto it = this->begin(); it != pos.node(); ++it)
        result = result->next_;
    return result;
}
template<class... Args>
iterator emplace(const_iterator pos, Args&&... args) {
    iterator this_it = this->begin();
    for (; this_it != pos; ++this_it) {;}
    return this->insert(this_it, value_type(std::forward<Args>(args)...));
}
template<class... Args>
void emplace_back(Args&&... args) {
    this->insert(this->end(), value_type(std::forward<Args>(args)...));
}
template<class... Args>
void emplace_front(Args&&... args) {
    this->insert(this->begin(), value_type(std::forward<Args>(args)...));
}
            };
}
#endif // S21_LIST_H_


