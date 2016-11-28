/* Find the height of a tree assuming root node to be at height 1 */

#include <iostream>
#include "tree.h"

using namespace std;

template <typename T>
int getHeight(btNode<T> const& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);
    root->left->right->left = make_node<int>(9);

    cout << "Height of tree: " << getHeight(*root) << endl;

    return 0;
}

template <typename T>
int getHeight(btNode<T> const& node) {
    int leftHeight = 0,
        rightHeight = 0;

    if(node.left)
        leftHeight = getHeight(*node.left);

    if(node.right)
        rightHeight = getHeight(*node.right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
