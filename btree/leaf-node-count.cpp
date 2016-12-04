/* Count the number f leaf nodes in a binary tree */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
size_t getLeafNodeCount(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(2);
    root->left->left = make_node<int>(3);
    root->left->right = make_node<int>(4);
    root->right->left = make_node<int>(3);
    root->right->right = make_node<int>(4);

    cout << "Leaf node count: " << getLeafNodeCount(root) << endl;

    return 0;
}

template <typename T>
size_t getLeafNodeCount(const node_ptr<T>& node) {
    if(!node)
        return 0;

    if(node->left == nullptr && node->right == nullptr)
        return 1;

    return getLeafNodeCount(node->left) + getLeafNodeCount(node->right);
}
