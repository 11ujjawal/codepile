/* Print node at distance k */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
void printNode(const node_ptr<T>& node, size_t dist);

int main(void) {
    auto const root = make_node<int>(10);
    root->left = make_node<int>(-2);
    root->right = make_node<int>(6);
    root->left->left = make_node<int>(8);
    root->left->right = make_node<int>(-4);
    root->right->left = make_node<int>(7);
    root->right->right = make_node<int>(5);

    printNode(root, 1);

    return 0;
}

template <typename T>
void printNode(const node_ptr<T>& node, size_t dist) {
    if(!node)
        return;

    if(dist == 0)
        cout << node->data << ' ';

    printNode(node->left, dist - 1);
    printNode(node->right, dist - 1);
}
