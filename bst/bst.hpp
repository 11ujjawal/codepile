/* Class definition for Binary Search Tree */

#ifndef _BST_HPP
#define _BST_HPP

#include "tree.hpp"

template <class T>
class bst {
    node_ptr<T> root;
    node_ptr<T> addNode(node_ptr<T> node, const T& value);
    bool findNode(const node_ptr<T>& node, const T& key);
public:
    bst() {
        root = nullptr;
    }
    void insert(T const& value);
    bool find(T const& value);
    T min();
};

#endif
