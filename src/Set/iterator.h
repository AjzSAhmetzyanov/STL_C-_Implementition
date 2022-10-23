#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "compare.h"
#include "rb_tree_node.h"

namespace s21 {
    template <class T, class Compare = s21::Compare<T>>
    class TreeIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type *;
        using reference = value_type &;
        using cmp_type = Compare;
        using node_type = TreeNode<value_type, cmp_type>;
        using node_pointer = TreeNode<value_type, cmp_type> *;
        using iterator = TreeIterator<value_type, cmp_type>;

    protected:
        node_pointer pointer_;
        cmp_type comp_;

    public:
        TreeIterator() : pointer_(nullptr) { ; }                        // базовый конструктор
        TreeIterator(node_pointer TreeNode) : pointer_(TreeNode) { ; }  // параметризированный конструктор
        TreeIterator(const TreeIterator &other) : TreeIterator() {  // копирование
            pointer_ = other.pointer_;
        }
        TreeIterator(TreeIterator &&other) {  // перемещение
            pointer_ = other.pointer_;
        }
        ~TreeIterator() {}
        node_pointer base() const { return pointer_; }
        const value_type operator*() const { return pointer_->key_; }
        bool operator==(const iterator &other) { return pointer_ == other.pointer_; }
        bool operator!=(const iterator &other) { return pointer_ != other.pointer_; }
        iterator &operator=(const iterator &other) {
            pointer_ = other.pointer_;
            return *this;
        }
        iterator &operator=(iterator &&other) {
            pointer_ = other.pointer_;
            return *this;
        }

        iterator operator++() {  // pre-increment
            if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else if (pointer_ == base()->get_max()) {
                pointer_ = base()->get_nill();
            } else {
                pointer_ = pointer_->findNext_();
            }
            return *this;
        }

        iterator operator++(int) {  // post-increment
            iterator tmp(*this);
            if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else if (pointer_ == base()->get_max()) {
                pointer_ = base()->get_nill();
            } else {
                pointer_ = pointer_->findNext_();
            }
            return tmp;
        }

        iterator operator--() {  // pre-decrement
            if (pointer_ == base()->get_min()) {
                pointer_ = base()->get_nill();
            } else if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else {
                pointer_ = pointer_->findPrev_();
            }
            return *this;
        }

        iterator operator--(int) {  // post-decrement
            iterator tmp(*this);
            if (pointer_ == base()->get_min()) {
                pointer_ = base()->get_nill();
            } else if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else {
                pointer_ = pointer_->findPrev_();
            }
            return tmp;
        }

        bool operator>(const iterator &other) { return pointer_ > other.pointer_; }
        bool operator<(const iterator &other) { return pointer_ < other.pointer_; }
        bool operator<=(const iterator &other) { return pointer_ <= other.pointer_; }
        bool operator>=(const iterator &other) { return pointer_ >= other.pointer_; }

    };  // class TreeIterator

    template <class T, class Compare = s21::Compare<T>>
    class TreeConstIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using cmp_type = Compare;
        using node_pointer = TreeNode<value_type, cmp_type> *;
        using const_node_pointer = const TreeNode<value_type, cmp_type> *;
        using const_iterator = TreeConstIterator<value_type, cmp_type>;

    protected:
        node_pointer pointer_;
        cmp_type comp_;

    public:
        TreeConstIterator() : pointer_(nullptr) { ; }  // базовый конструктор
        TreeConstIterator(node_pointer TreeNode) : pointer_(TreeNode) { ; }  // параметризированный конструктор
        TreeConstIterator(const const_iterator &other) : TreeConstIterator() {  // копирование
            pointer_ = other.pointer_;
        }
        TreeConstIterator(const_iterator &&other) {  // перемещение
            pointer_ = other.pointer_;
        }
        ~TreeConstIterator() {}
        const_node_pointer base() const { return pointer_; }
        const value_type operator*() const { return pointer_->key_; }
        bool operator==(const const_iterator &other) { return pointer_ == other.pointer_; }
        bool operator!=(const const_iterator &other) { return pointer_ != other.pointer_; }
        const_iterator &operator=(const const_iterator &other) {
            pointer_ = other.pointer_;
            return *this;
        }
        const_iterator &operator=(const_iterator &&other) {
            pointer_ = other.pointer_;
            return *this;
        }

        const_iterator operator++() {  // pre-increment
            if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else if (pointer_ == base()->get_max()) {
                pointer_ = base()->get_nill();
            } else {
                pointer_ = pointer_->findNext_();
            }
            return *this;
        }

        const_iterator operator++(int) {  // post-increment
            TreeConstIterator tmp(*this);
            if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else if (pointer_ == base()->get_max()) {
                pointer_ = base()->get_nill();
            } else {
                pointer_ = pointer_->findNext_();
            }
            return tmp;
        }

        const_iterator operator--() {  // pre-decrement
            if (pointer_ == base()->get_min()) {
                pointer_ = base()->get_nill();
            } else if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else {
                pointer_ = pointer_->findPrev_();
            }
            return *this;
        }

        const_iterator operator--(int) {  // post-decrement
            TreeConstIterator tmp(*this);
            if (pointer_ == base()->get_min()) {
                pointer_ = base()->get_nill();
            } else if (pointer_ == base()->get_nill()) {
                pointer_ = base()->get_max();
            } else {
                pointer_ = pointer_->findPrev_();
            }
            return tmp;
        }

        bool operator>(const const_iterator &other) { return pointer_ > other.pointer_; }
        bool operator<(const const_iterator &other) { return pointer_ < other.pointer_; }
        bool operator<=(const const_iterator &other) { return pointer_ <= other.pointer_; }
        bool operator>=(const const_iterator &other) { return pointer_ >= other.pointer_; }
    };  // class TreeConstIterator
}  // namespace s21
#endif // ITERATOR_H_