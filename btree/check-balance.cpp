/* Check whether the given tree is balanced or not */

#include <iostream>
#include <cmath>
#include "tree.hpp"

using namespace std;

template <typename T>
bool isBalanced(const node_ptr<T>& node);

template <typename T>
size_t getHeight(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<double>(-5.00001);
    root->left = make_node<double>(-9.5);
    root->right = make_node<double>(-3.23);
    root->left->left = make_node<double>(-7.45);
    root->left->right = make_node<double>(-5.978);
    root->right->left = make_node<double>(-2.43);
    root->right->right = make_node<double>(-7.34);

    cout << "Is first tree balanced: " << isBalanced(root) << endl;

    auto const btRoot = make_node<int>(3);
    btRoot->left = make_node<int>(4);
    btRoot->left->left = make_node<int>(1);
    cout << "Is second tree balanced: " << isBalanced(btRoot) << endl;

    return 0;
}

template <typename T>
bool isBalanced(const node_ptr<T>& node) {
    if(!node)
        return true;

    auto lHeight = getHeight(node->left);
    auto rHeight = getHeight(node->right);

    if(abs(lHeight - rHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return true;

    return false;
}

template <typename T>
size_t getHeight(const node_ptr<T>& node) {
    if(!node)
        return 0;

    size_t lHeight = getHeight(node->left);
    size_t rHeight = getHeight(node->right);

    if(lHeight > rHeight)
        return lHeight + 1;
    else
        return rHeight + 1;
}
