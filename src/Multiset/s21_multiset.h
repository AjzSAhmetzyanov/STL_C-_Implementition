#ifndef S21_MULTISET_H_
#define S21_MULTISET_H_

#include "../Set/compare.h"
#include "../Set/s21_set.h"
#include "iterator.h"
namespace s21 {
    template <class T, class Compare = s21::Compare<T>>
    class Multiset : public Set<T, Compare> {
    public:
        using key_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        using value_type = key_type;
        using comp_ = Compare;
        using node_type = TreeNode<key_type , comp_>;
        using node_pointer = typename Set<value_type, comp_>::node_pointer;
        using iterator = TreeIterator<key_type, comp_>;
        using const_iterator = TreeConstIterator<key_type, comp_>;
    private:
        std::allocator<Set<T, Compare>> alloc_;
    public:
        Multiset() : Set<key_type, comp_>() { ; }
        Multiset(std::initializer_list<key_type> const &items) : Set<key_type, comp_>() {
            for (auto it = items.begin(); it != items.end(); it++) insert(*it);
        }
        Multiset(const Multiset &other) : Set<key_type, comp_>() {
            for (auto it = other.begin(); it != other.end(); it++) insert(*it);
        }
        Multiset(Multiset &&other) : Set<key_type, comp_>() {
            delete this->nill_;
            this->root_ = other.root_;
            this->size_ = other.size_;
            this->nill_ = other.nill_;
            other.root_ = nullptr;
            other.nill_ = nullptr;
            other.size_ = 0;
        }
        ~Multiset() {}

    public:
        size_type max_size() { return alloc_.max_size(); }
        void operator=(Multiset &&other) {
            Set<value_type, comp_>::clearData_(this->root_);
            delete this->nill_;
            this->root_ = other.root_;
            this->size_ = other.size_;
            this->nill_ = other.nill_;
            other.root_ = nullptr;
            other.nill_ = nullptr;
            other.size_ = 0;
        }

        iterator insert(const value_type& value) {
            if (this->empty()) {
                Set<value_type, comp_>::Insert_new_element(value);
            } else {
                Insert_nonull_tree(value);
            }
        }

        void merge(Multiset& other) {

        }
        size_type count(const value_type &key) {
            size_type result = 0;
            for (auto it = this->find(key); this->comp_.eq(*it, key) && it != this->end(); it++) result++;
            return result;
        }
        std::pair<iterator, iterator> equal_range(const value_type &key) {
            auto it_begin = this->find(key);
            auto it_end = it_begin;
            for (; this->comp_.eq(*it_end, key) && it_end != this->end(); it_end++) {
                ;
            }
            std::pair<iterator, iterator> res_pair = {it_begin, it_end};
            return res_pair;
        }
        iterator lower_bound(const value_type &key) {
            auto result_it = this->begin();
            for (; this->comp_.lt(*result_it, key) && result_it != this->end(); result_it++) {
                ;
            }
            return result_it;
        }
        iterator upper_bound(const value_type &key) {
            auto result_it = this->begin();
            for (; this->comp_.le(*result_it, key) && result_it != this->end(); result_it++) {
                if (result_it == this->end()) break;
            }
            return result_it;
        }

        //helpers
    private:
        iterator Insert_nonull_tree(const key_type &value) {

        }
    };
}  // namespace s21

#endif  //  S21_MULTISET_H_