/* Fetch the inorder predecessor and successor of a bst */

#include <iostream>
#include "tree.hpp"

using namespace std;

/* Template function to fetch the predecessor of the given node */
template <typename T>
T* getPredecessor(const node_ptr<T>& node, const T& key);

/* Template function to fetch the successor of the given node */
template <typename T>
T* getSuccessor(const node_ptr<T>& node, const T& key);

int main(void) {
    node_ptr<int> root = make_bst({1, 2, 3, 4, 5, 6, 7});
    print(root);

    /* Fetch the predecessor */
    auto predecessor = getPredecessor(root, 6);
    if(predecessor)
        cout << "Predecessor of 6: " << *predecessor << endl;

    /* Fetch the successor */
    auto successor = getSuccessor(root, 6);
    if(successor)
        cout << "Successor of 6: " << *successor << endl;

     return 0;
}

/* Function definition to fetch the predecessor of the given node */
template <typename T>
T* getPredecessor(const node_ptr<T>& node, const T& key) {
    if(!node)
        return nullptr;

    if(node->data == key) {
        node_ptr<T> leftKey = node->left;

        while(leftKey && leftKey->right)
            leftKey = leftKey->right;

        return &leftKey->data;
    }

    if(node->data > key)
        return getPredecessor(node->left, key);
    else
        return getPredecessor(node->right, key);
}

/* Function definition to fetch the successor of the given node */
template <typename T>
T* getSuccessor(const node_ptr<T>& node, const T& key) {
    if(!node)
        return nullptr;

    if(node->data == key) {
        node_ptr<T> rightKey = node->right;

        while(rightKey && rightKey->left)
            rightKey = rightKey->left;

        return &rightKey->data;
    }

    if(node->data > key)
        return getSuccessor(node->left, key);
    else
        return getSuccessor(node->right, key);
}
