#ifndef ITERATOR_H_
#define ITERATOR_H_
namespace s21 {
    template <typename T>
    struct Node {
        Node<T>* prev_;
        Node<T>* next_;
        T data_;
        Node(T data = T(), Node *next = nullptr, Node *prev = nullptr) {
            this->data_ = data;
            this->next_ = next;
            this->prev_ = prev;
        }
    };
    template <class T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using node_pointer = Node<value_type>*;

    private:
        node_pointer iterator_;

    public:
        Iterator() : iterator_(nullptr) {}
        Iterator(node_pointer other_iterator) : iterator_(other_iterator) {}
        Iterator(const Iterator &other_iterator) : iterator_(other_iterator.iterator_) {}
        Iterator(Iterator &&other_iterator) : iterator_(other_iterator.iterator_) {}
        ~Iterator() { iterator_ = nullptr;}

        Iterator &operator++() {
            iterator_ = iterator_->next_;
            return *this;
        }
        Iterator &operator++(int) {
            auto iter = *this;
            iter.iterator_ = iter.iterator_->next_;
            return *this;
        }
        Iterator &operator--() {
            iterator_ = iterator_->prev_;
            return *this;
        }
        bool operator==(const Iterator &iter) {return iterator_->data_ == iter.iterator_->data_;}
        bool operator!=(const Iterator &iter) {return iterator_ != iter.iterator_;}
        void operator=(const Iterator &it) { iterator_ = it.iterator_; }
        void operator=(Iterator &&it) { iterator_ = it.iterator_; }
        reference operator*() { return iterator_->data_;}

        Iterator operator+(int value) {
            Iterator tmp(*this);
            return (tmp += value);
        }

        Iterator operator-(int value) {
            Iterator tmp(*this);
            return (tmp -= value);
        }

        Iterator &operator+=(int value) {
            for (int i = 0; i < value; i++) {
                iterator_ = iterator_->next_;
            }
            return *this;
        }

        Iterator &operator-=(int value) {
            for (int i = 0; i < value; i++) {
                iterator_ = iterator_->prev_;
            }
            return *this;
        }

        pointer operator->() { return iterator_->data_; }

        node_pointer node() {
            node_pointer pointer = iterator_;
            return pointer;
        }
    };
    template <class T>
    class ConstIterator {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using node_pointer = Node<value_type>*;

    private:
        node_pointer iterator_;

    public:
        ConstIterator() : iterator_(nullptr) {}
        ConstIterator(node_pointer other_iterator) : iterator_(other_iterator) {}
        ConstIterator(const ConstIterator &other_iterator) : iterator_(other_iterator.iterator_) {}
        ConstIterator(ConstIterator &&other_iterator) : iterator_(other_iterator.iterator_) {}
        ~ConstIterator() { iterator_ = nullptr;}

        ConstIterator &operator++() {
            iterator_ = iterator_->next_;
            return *this;
        }
        ConstIterator &operator++(int) {
            auto iter = *this;
            iter.iterator_ = iter.iterator_->next_;
        }
        ConstIterator &operator--() {
            iterator_ = iterator_->prev_;
            return *this;
        }
        bool operator==(const ConstIterator &iter) {return iterator_->data_ == iter.iterator_->data_;}
        bool operator!=(const ConstIterator &iter) {return iterator_ != iter.iterator_;}
        void operator=(const ConstIterator &it) { iterator_ = it.iterator_; }
        void operator=(ConstIterator &&it) { iterator_ = it.iterator_; }
        reference operator*() { return *(iterator_->data_);}

        ConstIterator operator+(int value) {
            ConstIterator tmp(*this);
            return (tmp += value);
        }

        ConstIterator operator-(int value) {
            ConstIterator tmp(*this);
            return (tmp -= value);
        }

        ConstIterator &operator+=(int value) {
            for (int i = 0; i < value; i++) {
                iterator_ = iterator_->next_;
            }
            return *this;
        }

        ConstIterator &operator-=(int value) {
            for (int i = 0; i < value; i++) {
                iterator_ = iterator_->prev_;
            }
            return *this;
        }

        pointer operator->() { return iterator_->data_; }

        node_pointer node() {
            node_pointer pointer = iterator_;
            return pointer;
        }
    };
}
#endif // ITERATOR_H_