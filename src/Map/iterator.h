#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <iostream>
namespace s21 {
    template<class Value>
    struct Node {
    public:
        explicit Node(Value *scrval = 0) : _value(scrval), _parent(0), _left(0), _right(0), is_black(false),
                                           is_nil(false) {}

        Value *_value;
        Node *_parent;
        Node *_left;
        Node *_right;
        bool is_black;
        bool is_nil;

        Node(const Node &other) {
            this->_value = other._value;
            this->_parent = other._parent;
            this->_left = other._left;
            this->_right = other._right;
            this->is_black = other.is_black;
            this->is_nil = other.is_nil;
        };

        Node &operator=(const Node &other) {
            this->_value = other._value;
            this->_parent = other._parent;
            this->_left = other._left;
            this->_right = other._right;
            this->is_black = other.is_black;
            this->is_nil = other.is_nil;
            return *this;
        };

        virtual ~Node() {}
    };

    template<typename T>
    class TreeIterator {
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef  T value_type;
        typedef  T& reference;
        typedef  T* pointer;
        typedef std::ptrdiff_t difference_type;
        typedef Node<T> *node_pointer;

    private:

        node_pointer _node;

        node_pointer tree_min(node_pointer n) const {
            while (n->_left != NULL && !n->_left->is_nil) {
                n = n->_left;
            }
            return n;
        }

        node_pointer tree_max(node_pointer n) const {
            while (!n->_right->is_nil) {
                n = n->_right;
            }
            return n;
        }

    public:
        TreeIterator() {};

        TreeIterator(void *node) : _node(static_cast<node_pointer>(node)) {}

        TreeIterator(const TreeIterator<T> &other) {
            *this = other;
        }

        TreeIterator &operator=(const TreeIterator<T> &other) {
            this->_node = other.node();
            return *this;
        }

        reference operator*() const {
            return *(_node->_value);
        }

        pointer operator->() const {
            return _node->_value;
        }

        TreeIterator &operator++() {
            if (_node->_right && !_node->_right->is_nil)
                _node = tree_min(_node->_right);
            else {
                node_pointer n = _node->_parent;
                while (n != NULL && _node == n->_right) {
                    _node = n;
                    n = n->_parent;
                }
                _node = n;
            }
            return *this;
        }

        TreeIterator operator++(int) {
            TreeIterator<value_type> temp = *this;
            if (!_node->_right->is_nil) {
                _node = tree_min(_node->_right);
            } else {
                node_pointer y = _node->_parent;
                while (y != NULL && _node == y->_right) {
                    _node = y;
                    y = y->_parent;
                }
                _node = y;
            }
            return temp;
        }

        TreeIterator &operator--() {
            if (_node->_left && !_node->_left->is_nil)
                _node = tree_max(_node->_left);
            else {
                node_pointer n = _node->_parent;
                while (n != NULL && _node == n->_left) {
                    _node = n;
                    n = n->_parent;
                }
                _node = n;
            }
            return *this;
        }

        TreeIterator operator--(int) {
            TreeIterator<value_type> temp = *this;
            if (_node->_left && !_node->_left->is_nil)
                _node = tree_max(_node->_left);
            else {
                node_pointer n = _node->_parent;
                while (n != NULL && _node == n->_left) {
                    _node = n;
                    n = n->_parent;
                }
                _node = n;
            }
            return temp;
        }

        node_pointer node() const {
            return _node;
        }
    };

    template<typename A, typename B>
    bool operator==(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs) {
        return lhs.node() == rhs.node();
    }

    template<typename A, typename B>
    bool operator!=(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs) {
        return lhs.node() != rhs.node();
    }
}
#endif  // ITERATOR_H_