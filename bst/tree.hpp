/* Class definition for Binary Search Tree */

#include "tree-template.hpp"

template <class T>
class bst {
    node_ptr<T> root;
    node_ptr<T> addNode(node_ptr<T> node, T const& value);
    bool findNode(btNode<T> const& node, T const& value);
public:
    bst() {
        root = nullptr;
    }
    void insert(T const& value);
    bool find(T const& value);
};
