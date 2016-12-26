/* Check if two trees are identical or not */

#include <iostream>
#include "tree.hpp"

using namespace std;

template <typename T>
bool checkIdentical(const node_ptr<T>& nodeOne, const node_ptr<T>& nodeTwo);

int main(void) {
    auto const rootOne = make_tree({1, 2, 3, 4, 5, 6, 7});
    auto const rootTwo = make_tree({1, 2, 3, 4, 5});
    auto const rootThree = make_tree({1, 2, 3, 4, 5, 6, 7});

    cout << "Are trees one and two identical? " << checkIdentical(rootOne, rootTwo) << endl;
    cout << "Are trees one and three identical? " << checkIdentical(rootOne, rootThree) << endl;
    
    return 0;
}

template <typename T>
bool checkIdentical(const node_ptr<T>& nodeOne, const node_ptr<T>& nodeTwo) {
    if(!nodeOne && !nodeTwo)
        return true;

    if(!nodeOne || !nodeTwo)
        return false;

    return (nodeOne->data && nodeTwo->data) &&
            checkIdentical(nodeOne->left, nodeTwo->left) &&
            checkIdentical(nodeOne->right, nodeTwo->right);
}
