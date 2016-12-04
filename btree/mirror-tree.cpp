/* Convert a binary tree to its mirror tree */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
void mirror(const node_ptr<T>& node);

template <typename T>
void printInOrder(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "Tree before: ";
    printInOrder(root);
    mirror(root);
    cout << "\nTree after: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

template <typename T>
void mirror(const node_ptr<T>& node) {
    if(!node)
        return;

    mirror(node->left);
    mirror(node->right);
    swap(node->left, node->right);
}

template <typename T>
void printInOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    printInOrder(node->left);
    cout << node->data << ' ';
    printInOrder(node->right);
}
