/* Find the height of a tree assuming root node to be at height 1 */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
size_t getHeight(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);
    root->left->right->left = make_node<int>(9);

    cout << "Height of tree: " << getHeight(root) << endl;

    return 0;
}

template <typename T>
size_t getHeight(const node_ptr<T>& node) {
    if(!node)
        return 0;

    size_t leftHeight = getHeight(node->left);
    size_t rightHeight = getHeight(node->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
