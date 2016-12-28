/* For every node the data value should be equal to the sum of data values of
 * left and right children */

#include <iostream>
#include <string>
#include "tree.hpp"

using namespace std;

template <typename T>
bool checkSumProperty(const node_ptr<T>& node);

int main(void) {
    auto const root = make_tree({10, 8, 2, 3, 5, 2});
    cout << "Is the children sum property satisfied? " << checkSumProperty(root) << endl;

    /* Tree representation -
     *
     *          abcd
     *          /  \
     *        ab    cd
     *
     */
    auto const newRoot = make_tree({string("abcd"), string("ab"), string("cd")});
    cout << "Is the children sum property satisfied? " << checkSumProperty(newRoot) << endl;

    return 0;
}

template <typename T>
bool checkSumProperty(const node_ptr<T>& node) {
    if(!node || !(node->left && node->right))
        return true;

    T childrenSum = (node->left ? node->left->data : 0) + (node->right ? node->right->data : 0);

    return (childrenSum == node->data) &&
            checkSumProperty(node->left) &&
            checkSumProperty(node->right);
}
