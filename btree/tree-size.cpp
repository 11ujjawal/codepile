/* Find the size of a binary tree */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
size_t getSize(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "Size of tree: " << getSize(root) << endl;

    return 0;
}

template <typename T>
size_t getSize(const node_ptr<T>& node) {
    if(!node)
        return 0;

    return 1 + getSize(node->left) + getSize(node->right);
}
