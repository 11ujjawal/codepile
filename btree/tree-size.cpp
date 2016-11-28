/* Find the size of a binary tree */

#include <iostream>
#include "tree.h"

using namespace std;

template <typename T>
int getSize(btNode<T> const& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "Size of tree: " << getSize(*root) << endl;

    return 0;
}

template <typename T>
int getSize(btNode<T> const& node) {
    int leftSize = 0,
        rightSize = 0;

    if(node.left)
        leftSize = getSize(*node.left);

    if(node.right)
        rightSize = getSize(*node.right);

    return leftSize + rightSize + 1;
}
