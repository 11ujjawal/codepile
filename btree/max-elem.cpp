/* Find the maximum element in a binary tree */

#include <iostream>
#include <limits>
#include "tree.hpp"

using namespace std;

/* Template declaration for finding the maximum value of an element of the given type */
template <typename T>
T getMax(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<double>(-5.00001);
    root->left = make_node<double>(-9.5);
    root->right = make_node<double>(-3.23);
    root->left->left = make_node<double>(-7.45);
    root->left->right = make_node<double>(-5.978);
    root->right->left = make_node<double>(-2.43);
    root->right->right = make_node<double>(-7.34);

    cout << getMax(root) << endl;

    return 0;
}

/* Template definition for finding the maximum value of an element of the given type */
template <typename T>
T getMax(const node_ptr<T>& node) {
    if(!node)
        return numeric_limits<T>::lowest();

    T leftMax, rightMax, max = node->data;

    leftMax = getMax(node->left);
    rightMax = getMax(node->right);

    if(leftMax > max)
        max = leftMax;

    if(rightMax > max)
        max = rightMax;

    return max;
}
