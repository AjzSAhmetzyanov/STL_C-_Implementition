#ifndef S21_MAP_H_
#define S21_MAP_H_
#include "../Vector/utility.h"
#include "../Vector/s21_vector.h"
#include <memory>
#include "../Set/compare.h"
#include "red_black_tree.h"
namespace s21 {

    template <class Key, class T, class Compare = s21::Pair_compare<Key, T>, class Allocator = std::allocator<std::pair<const Key, T> > >

    class Map{
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef std::pair<const key_type , mapped_type> value_type;
        typedef Allocator allocator_type;
        typedef const value_type & reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef s21::RedBlackTree<value_type, key_compare , allocator_type> tree_type;
        typedef typename tree_type::iterator				iterator;
        typedef typename tree_type::const_iterator			const_iterator;

    private:
        allocator_type	_alloc;
        tree_type		_tree;
        key_compare		_compare;

    public:

        explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
                _alloc(alloc), _tree(tree_type(comp, alloc)), _compare(comp) {}

        Map(std::initializer_list<value_type> const &items)  {
            for (auto it = items.begin(); it != items.end(); it++)
                insert(*it);
        }

        mapped_type& operator[](const key_type& key){
            return (*((this->insert(std::make_pair(key,mapped_type()))).first)).second;
        }

        size_type size() const {
            return (_tree.size());
        }

        size_type max_size() const{
            return (_tree.max_size());
        }

        bool empty() const{
            return (_tree.empty());
        }

        iterator begin(){
            return (_tree.begin());
        }

        iterator end() {
            return (_tree.end());
        }

        void clear() {
            _tree.clear();
        }

        std::pair<iterator, bool> insert(const value_type& value){
            return (_tree.insert(value));
        }

        iterator insert(iterator hint, const value_type& value){
            return (_tree.insert(hint, value));
        }

        void erase(iterator pos){
            _tree.erase(pos);
        }

        size_type erase(const Key& key){
            return (_tree.erase(std::make_pair(key, mapped_type())));
        }

        void erase(iterator first, iterator last){
            _tree.erase(first, last);
        }

        iterator find(const Key& key){
            return _tree.find(std::make_pair(key, mapped_type()));
        }

        size_type count( const Key& key ) const{
            return (_tree.count(std::make_pair(key, mapped_type())));
        }

        void swap(Map & other){
            std::swap(this->_compare, other._compare);
            _tree.swap(other._tree);
        }

        iterator lower_bound(const key_type& key){
            return (_tree.lower_bound(std::make_pair(key, mapped_type())));
        }

        const_iterator lower_bound(const key_type& key) const{
            return (_tree.lower_bound(std::make_pair(key, mapped_type())));
        }

        iterator upper_bound(const key_type& key){
            return (_tree.upper_bound(std::make_pair(key, mapped_type())));
        }

        const_iterator upper_bound(const key_type& key) const{
            return (_tree.upper_bound(std::make_pair(key, mapped_type())));
        }

        std::pair<iterator, iterator> equal_range(const key_type & key){
            return (_tree.equal_range(std::make_pair(key, mapped_type())));
        }

        std::pair<const_iterator, const_iterator> equal_range(const key_type & key) const{
            return (_tree.equal_range(std::make_pair(key, mapped_type())));
        }

        mapped_type & at(const key_type &key) const {
            return _tree.at(std::make_pair(key, mapped_type()));
        }
        void merge(Map& other) {
            for (auto it = other.begin(); it != other.end(); it++)
                this->insert(*it);
           //tree.clear();
        }

        std::pair<iterator, bool> insert_or_assign(const key_type &key, const mapped_type &obj) const {
         return _tree.insert_or_assign(std::make_pair(key, obj));
        }

        template <class... Args>
        Vector<std::pair<iterator, bool>> emplace(Args &&...args) {
            Vector<std::pair<iterator, bool>> result;
            result.push_back(insert(std::forward<Args>(args)...));
            return result;
        }
        bool contains(const Key &key) const {
            return (_tree.contains(std::make_pair(key, mapped_type())));
        }

        template<class _Key, class _T, class _Compare, class _Alloc>
        friend bool operator==(const Map<_Key, _T, _Compare, _Alloc> & lhs,
                               const Map<_Key, _T, _Compare, _Alloc>& rhs);

        template<class _Key, class _T, class _Compare, class _Alloc>
        friend bool operator<(const Map<_Key, _T, _Compare, _Alloc> & lhs,
                              const Map<_Key, _T, _Compare, _Alloc>& rhs);
    };

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return (lhs._tree == rhs._tree);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return (lhs._tree < rhs._tree);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return !(lhs > rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const Map<Key, T, Compare, Alloc> & lhs, const Map<Key, T, Compare, Alloc> & rhs){
        return !(lhs < rhs);
    }


    template<class Key, class T, class Compare, class Alloc>
    void swap(const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs){
        lhs.swap(rhs);
    }
}// namespace s21
#endif  // S21_MAP_H_