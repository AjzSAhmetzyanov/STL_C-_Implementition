#ifndef RB_TREE_NODE_H_
#define RB_TREE_NODE_H_
#include <cstddef>
#include "compare.h"
#include "s21_set.h"
namespace s21 {
    template<class Key, class Compare = s21::Compare<Key>>
    class TreeNode {
    public:
        using key_type = Key;
        using reference = Key &;
        using const_reference = const Key &;
        using cmp_type = Compare;
        using size_type = size_t;

    public:
        cmp_type comp_;
        TreeNode *parent_;
        TreeNode *left_;
        TreeNode *right_;
        key_type key_;

        TreeNode() : parent_(nullptr), left_(nullptr), right_(nullptr) { ; }

        TreeNode(key_type data, TreeNode *parent = nullptr, TreeNode *left = nullptr, TreeNode *right = nullptr)
                : parent_(parent), left_(left), right_(right), key_(data) {
            ;
        }

        TreeNode(const TreeNode &other) = default;

        TreeNode(TreeNode &&other) = default;

        constexpr TreeNode &operator=(const TreeNode &other) = default;

        ~TreeNode() { ; }

    public:
        TreeNode *get_nill() {
            TreeNode *nill = this;
            while (nill->right_ != nullptr) nill = nill->right_;
            return nill;
        }

        TreeNode *get_root() {
            TreeNode *result = this;
            while (result->parent_ != nullptr) {
                result = result->parent_;
            }
            return result;
        }

        TreeNode *get_max() {
            TreeNode *root = get_root();
            while (root->right_ != get_nill()) root = root->right_;
            if (comp_.eq(root->left_->key_, root->key_)) {
                while (root->left_ != get_nill()) root = root->left_;
            }
            return root;
        }

        TreeNode *get_min() {
            TreeNode *root = get_root();
            while (root->left_ != get_nill()) root = root->left_;
            return root;
        }

        TreeNode *findNext_() {
            TreeNode *node = this;
            Key current_value = node->key_;
            if (node->right_ != get_nill()) {
                node = node->right_;
                while (node->left_ != get_nill()) {
                    node = node->left_;
                }
            } else {
                if (node->parent_ != nullptr) {
                    TreeNode *parent_TreeNode = node->parent_;
                    while (node == parent_TreeNode->right_) {
                        node = parent_TreeNode->right_;
                        parent_TreeNode = parent_TreeNode->parent_;
                    }
                    if (node->right_ != parent_TreeNode) {
                        node = parent_TreeNode;
                    }
                    if (comp_.lt(node->key_, current_value)) {
                        while (comp_.gt(current_value, node->key_)) {
                            node = node->parent_;
                        }
                    }
                }
            }
            return node;
        }

        TreeNode *findPrev_() {
            TreeNode *node = this;
            Key current_value = node->key_;
            if (node->left_ != get_nill()) {
                node = node->left_;
                while (node->right_ != get_nill()) {
                    node = node->right_;
                }
            } else {
                if (node->parent_ != nullptr) {
                    TreeNode *parent_TreeNode = node->parent_;
                    while (node == parent_TreeNode->left_) {
                        node = parent_TreeNode->left_;
                        parent_TreeNode = parent_TreeNode->parent_;
                    }
                    if (node->left_ != parent_TreeNode) {
                        node = parent_TreeNode;
                    }
                    if (comp_.gt(node->key_, current_value)) {
                        while (comp_.lt(current_value, node->key_)) {
                            node = node->parent_;
                        }
                    }
                }
            }
            return node;
        }
    };
}  // namespace s21
#endif  // RB_TREE_NODE_H_
