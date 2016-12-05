/* Print the ancestor of a given node */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
bool printAncestor(const node_ptr<T>& node, T key);

int main(void) {
    auto const root = make_node<int>(10);
    root->left = make_node<int>(-2);
    root->right = make_node<int>(6);
    root->left->left = make_node<int>(8);
    root->left->right = make_node<int>(-4);
    root->right->left = make_node<int>(7);
    root->right->right = make_node<int>(5);

    printAncestor(root, -4);
    cout << endl;

    return 0;
}

template <typename T>
bool printAncestor(const node_ptr<T>& node, T key) {
    if(!node)
        return false;

    if(node->data == key) {
        cout << node->data << ' ';
        return true;
    }

    if(printAncestor(node->left, key) || printAncestor(node->right, key)) {
        cout << node->data << ' ';
        return true;
    }

    return false;
}
