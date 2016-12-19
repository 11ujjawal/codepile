/* Check whether is binary tree is a BST or not */

#include <iostream>
#include <limits>
#include "tree.hpp"

using namespace std;

template <typename T>
bool check(const node_ptr<T>& node);

template <typename T>
bool checkBST(const node_ptr<T>& node, T min, T max);

int main(void) {
    auto rootOne = make_btree({1, 2, 3, 4, 5, 6, 7});
    auto rootTwo = make_bst({1, 2, 3, 4, 5, 6, 7});

    cout << "Trees in Level Order" << endl;

    print(rootOne);
    cout << "Is the above tree bst? " << check(rootOne) << endl;

    print(rootTwo);
    cout << "Is the above tree bst? " << check(rootTwo) << endl;

    return 0;
}

template <typename T>
bool check(const node_ptr<T>& node) {
    return checkBST(node, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

template <typename T>
bool checkBST(const node_ptr<T>& node, T min, T max) {
    if(!node)
        return true;

    if(node->data < min || node->data > max)
        return false;

    return checkBST(node->left, min, node->data - 1) && checkBST(node->right, node->data + 1, max);
}
