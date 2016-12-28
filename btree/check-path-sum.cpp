/* Check whether the sum of a path is equal to a given number */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
bool checkPathSum(const node_ptr<T>& node, T sum);

int main(void) {
    auto const root = make_tree({1, 2, 3, 4, 5, 6, 7, 8, 9});

    cout << "Does tree have a path sum equal to 11: " << checkPathSum(root, 11) << endl;
    cout << "Does tree have a path sum equal to 20: " << checkPathSum(root, 20) << endl;

    return 0;
}

template <typename T>
bool checkPathSum(const node_ptr<T>& node, T sum) {
    if(!node)
        return sum == T();

    T currSum = sum - node->data;

    /* If the current sum is equal to the default value, and the current node
     * is a leaf, then the sum property exists
     */
    if(!currSum && !node->left && !node->right)
        return true;

    return checkPathSum(node->left, currSum) || checkPathSum(node->right, currSum);
}
