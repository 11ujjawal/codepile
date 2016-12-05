/* Check if a binary tree is foldable or not */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
bool foldable(const node_ptr<T>& node);

template <typename T>
bool checkFoldable(const node_ptr<T>& nodeOne, const node_ptr<T>& nodeTwo);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);

    cout << "Foldable? " << foldable(root) << endl;

    return 0;
}

template <typename T>
bool foldable(const node_ptr<T>& node) {
    return checkFoldable(node->left, node->right);
}

template <typename T>
bool checkFoldable(const node_ptr<T>& nodeOne, const node_ptr<T>& nodeTwo) {
    if(!nodeOne && !nodeTwo)
        return true;

    if(!nodeOne || !nodeTwo)
        return false;

    return checkFoldable(nodeOne->left, nodeTwo->right) && checkFoldable(nodeOne->right, nodeTwo->left);
}
