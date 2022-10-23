#ifndef S21_SET_H_
#define S21_SET_H_
#include <initializer_list>
#include <iostream>
#include <utility>
#include "compare.h"
#include "rb_tree_node.h"
#include "../Vector/s21_vector.h"
#include "iterator.h"

namespace s21 {
    template <typename Key, class Compare = s21::Compare<Key>>
    class Set {
    public:
        using key_type = Key;
        using reference = Key &;
        using const_reference = const Key &;
        using cmp_type = Compare;
        using iterator = TreeIterator<key_type, cmp_type>;
        using const_iterator = TreeConstIterator<key_type, cmp_type>;
        using size_type = size_t;
        using node_type = TreeNode<Key, cmp_type>;
        using node_pointer = TreeNode<Key, cmp_type> *;

    protected:
        cmp_type comp_;
        node_pointer root_;
        node_pointer nill_ = new node_type();
        size_type size_ = 0;
        std::allocator<key_type> alloc_;

    public:
        Set() : root_(nullptr) { ; }

        Set(std::initializer_list<key_type> const &items) : Set() {
            for (auto it = items.begin(); it != items.end(); it++)
                insert(*it);
        }

        Set(const Set &other) : Set() {
            copy_(other.root_, other.nill_);
        }

        Set(Set &&other) : Set() {
            delete nill_;
            root_ = other.root_;
            size_ = other.size_;
            nill_ = other.nill_;
            other.root_ = nullptr;
            other.nill_ = nullptr;
            other.size_ = 0;
        }

        ~Set() {
            if (size_ != 0) clear();
            if (nill_) delete nill_;
        }

        bool empty() const { return size_ == 0; }
        size_type size() const noexcept { return size_; }
        size_type max_size() const noexcept { return alloc_.max_size(); }
        std::pair<iterator, bool> insert(const key_type &value) {
            // если root пустой , то вставляем на его место
            // если не пустой, тогда 1: если элемент существует , то его не добавляем , возвращаем false через пару
            // 2: если такого элемента нет, то его закидываем по правилам
            return Insert_new_element(value);
        }

        bool contains(const key_type &value) const {
            auto result = search_key(value);
            return result.second;
        }
        iterator begin() const {
            node_pointer begin_node = root_;
            if (size_ != 0) {
                while (begin_node->left_ != nill_) {
                    begin_node = begin_node->left_;
                    while (begin_node->right_ != nill_ && comp_.eq(begin_node->right_->key_, begin_node->key_))
                        begin_node = begin_node->right_;
                }
            } else {
                begin_node = nill_;
            }
            return iterator(begin_node);
        }
        const_iterator cbegin() const {
            node_pointer begin_node = root_;
            if (size_ != 0) {
                while (begin_node->left_ != nill_) {
                    begin_node = begin_node->left_;
                    while (begin_node->right_ != nill_ && comp_.eq(begin_node->right_->key_, begin_node->key_))
                        begin_node = begin_node->right_;
                }
            } else {
                begin_node = nill_;
            }
            return const_iterator(begin_node);
        }
        iterator end() const { return iterator(nill_); }
        const_iterator cend() const { return const_iterator(nill_); }
        void clear() {
            Clear_tree(this->root_);
            root_ = nullptr;
            size_ = 0;
        }

        void swap(Set &other) {
            node_pointer tmp_root = other.root_;
            node_pointer tmp_nill = other.nill_;
            size_type tmp_size = other.size_;
            other.root_ = this->root_;
            other.nill_ = this->nill_;
            other.size_ = this->size_;
            this->root_ = tmp_root;
            this->nill_ = tmp_nill;
            this->size_ = tmp_size;
        }
        void merge(Set &other) {
            //ищем уникальные элементы из второго дерева
            //если есть , то отправляем в 1 дерево
            if (!other.empty()) {
                if (other.root_ != nullptr) {
                    for (auto it_1 = other.begin(); it_1 != other.end(); it_1++) {
                        if (!this->contains(*it_1)) {
                            this->insert(*it_1);
                            other.size_--;
                        }
                    }
                }
            }
        }

        iterator find(const Key &value) {
            return search_key(value).second == true ? search_key(value).first : end();
        }

        void erase(iterator pos) {
           // node_pointer temp_note = pos.base();
            //if (temp_note == nullptr) std::cout << "sdf0" <<std::endl;
            erase_tree_pos(pos);
        }

        void operator=(Set &&other) {
            Clear_tree(root_);
            delete nill_;
            root_ = other.root_;
            size_ = other.size_;
            nill_ = other.nill_;
            other.root_ = nullptr;
            other.nill_ = nullptr;
            other.size_ = 0;
        }

        template <class... Args>
        Vector<std::pair<iterator, bool>> emplace(Args &&...args) {
            Vector<std::pair<iterator, bool>> result;
            result.push_back(insert(key_type(std::forward<Args>(args)...)));
            return result;
        }
        // helpers
    private:
        std::pair<iterator, bool> Insert_new_element(const key_type &value) {
            std::pair<iterator, bool> result = {root_, false};
            node_pointer new_element = new node_type(value, nullptr, nill_, nill_);
            if (empty()) {
                result = insert_to_null_tree(new_element);
            } else {
                result = Insert_new_element_to_nonul_tree(root_, new_element);
            }
            return result;
        }

        std::pair <iterator, bool> insert_to_null_tree(node_pointer new_element)  {
            std::pair<iterator,bool> result = {root_, false};
            root_ = new_element;
            size_++;
            nill_->parent_ = root_;
            iterator new_insert_iterator(new_element);
            result = {new_insert_iterator, true};
            return result;
        }

        std::pair<iterator, bool> Insert_new_element_to_nonul_tree(node_pointer root, node_pointer new_element) {
            std::pair<iterator, bool> result = {root, false};
            if (!contains(new_element->key_)) {
                if (comp_.gt(new_element->key_, root->key_)) {
                    result = insert_to_left(root, new_element);
                } else {
                    result = insert_to_right(root, new_element);
                }
            }
            return result;
        }

        std::pair<iterator, bool> insert_to_left(node_pointer root, node_pointer new_element) {
            std::pair<iterator, bool> result = {root, false};
            if (root->right_ == nill_) {
                root->right_ = new_element;
                new_element->parent_ = root;
                size_++;
                iterator new_1(root->right_);
                result = {new_1, true};
            } else {
                node_pointer next_ = root->right_;
                Insert_new_element_to_nonul_tree(next_, new_element);
            }
            return result;
        }
        std::pair<iterator, bool> insert_to_right(node_pointer root, node_pointer new_element) {
            std::pair<iterator, bool> result = {root, false};
            if (root->left_ == nill_) {
                root->left_ = new_element;
                new_element->parent_ = root;
                size_++;
                iterator new_2(root->left_);
                result = {new_2, true};
            } else {
                node_pointer next_1 = root->left_;
                Insert_new_element_to_nonul_tree(next_1, new_element);
            }
            return result;
        }

        void Clear_tree(node_pointer node) {
            if (node != nill_ && node != nullptr) {
                if (node->left_ != nill_) Clear_tree(node->left_);
                if (node->right_ != nill_) Clear_tree(node->right_);
                delete node;
            }
        }
        std::pair<iterator, bool> search_key(const key_type &value) const {
            bool result = false;
            node_pointer node = root_;
            while (node && node != nill_) {
                if (comp_.lt(value, node->key_)) {
                    node = node->left_;
                } else if (comp_.gt(value, node->key_)) {
                    node = node->right_;
                } else if (comp_.eq(value, node->key_)) {
                    result = true;
                    break;
                }
            }
            auto res_iter(node);
            std::pair<iterator, bool> res_search = {res_iter, result};
            return res_search;
        }

        void copy_(node_pointer node, node_pointer nill) {
            if (node != nullptr && node != nill) {
                if (node->left_ != nill) copy_(node->left_, nill);
                if (node->right_ != nill) copy_(node->right_, nill);
                insert(node->key_);
            }
        }

        void erase_tree_pos(iterator pos) {
            if (pos.base()->left_ == root_ && pos.base()->right_ == root_) { //если нет детей то удаляем его
                Delete_this_tree(pos);
            } else if (pos.base()->left_ == nill_ && pos.base()->right_ != nill_) { //если есть левый ребенок ,
                Delete_and_insert(pos); // то удаляем и ставим на его место левого ребенка
            } else if (pos.base()->left_ == nill_ && pos.base()->right_ != nill_) { //если есть правый ребенок,
                Delete_and_insert(pos);// то удаляем и ставим на его место правого ребенка
            } else {
                Delete_and_insert_min(pos); //если есть и левый и правый надо удалить и вставить
            } //минимальный эдемент
            //size_--;
        }

        void Delete_this_tree(iterator pos) {
            pos.base()->parent_ = nullptr;
            size_--;
        }

        void Delete_and_insert(iterator pos) {
          //  bool temp = true;
//            if (pos.base()->left_ == root_) {
//                iterator tmp_1 = pos.base()->right_;
//                result = tmp_1;
//                size_--;
//            } else
                if (pos.base()->right_ != root_) {
                //if(res == temp) {
               //     pos.base()->parent_ = pos.base()->right_;
                    root_ = root_->right_;
                    size_--;
                //}
            } else {
                    root_ = root_->left_;
                }
//            return pos.base()->parent_;
        }

        void Delete_and_insert_min(iterator pos) {
            root_ = root_->left_;
        }
    };
}  // namespace s21
#endif // S21_SET_H_
