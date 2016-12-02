/* Binary Search Tree implementation */

#include <iostream>
#include <string>
#include "tree.hpp"

int main(void) {
    /* BST for integers as data */
    bst<int> btree;
    btree.insert(10);
    btree.insert(80);
    btree.insert(30);
    btree.insert(20);

    std::cout << "Searching in BST ---> \n";
    std::cout << "Find 20: " << btree.find(20) << "\nFind 25: " << btree.find(25) << std::endl;

    /* BST for strings as data */
    bst<std::string> strBt;
    strBt.insert(std::string("tree"));
    strBt.insert(std::string("new tree"));

    std::cout << "Find 'new tree': " << strBt.find(std::string("new tree")) << std::endl;
    std::cout << "Find 'next tree': " << strBt.find(std::string("next tree")) << std::endl;

    return 0;
}

/* Template definition for insertion in bst */
template <class T>
void bst<T>::insert(T const& value) {
    root = addNode(std::move(root), value);
}

template <class T>
node_ptr<T> bst<T>::addNode(node_ptr<T> node, T const& value) {
    if(!node)
        return make_node<T>(value);

    if(node->data > value)
        node->left = addNode(std::move(node->left), value);
    else if(node->data < value)
        node->right = addNode(std::move(node->right), value);

    return node;
}

/* Templetion definition to find a value in bst */
template <class T>
bool bst<T>::find(T const& value) {
    return findNode(*root, value);
}

template <class T>
bool bst<T>::findNode(btNode<T> const& node, T const& value) {
    if(node.data == value)
        return true;

    if(node.data < value) {
        if(node.right)
            return findNode(*node.right, value);
    }
    else {
        if(node.left)
            return findNode(*node.left, value);
    }

    return false;
}
