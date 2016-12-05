/* Convert a given tree to sum tree */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
int sumTree(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(10);
    root->left = make_node<int>(-2);
    root->right = make_node<int>(6);
    root->left->left = make_node<int>(8);
    root->left->right = make_node<int>(-4);
    root->right->left = make_node<int>(7);
    root->right->right = make_node<int>(5);

    sumTree(root);

    return 0;
}

template <typename T>
int sumTree(const node_ptr<T>& node) {
    if(!node)
        return 0;

    int leftSum = sumTree(node->left);
    int rightSum = sumTree(node->right);

    int data = node->data;
    node->data = leftSum + rightSum;

    return data + node->data;
}
