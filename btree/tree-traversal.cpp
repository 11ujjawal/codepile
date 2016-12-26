/* Tree traversal in binary tree */

#include <iostream>
#include <string>
#include "tree.hpp"

using namespace std;

/* Template declaration for inOrder tree traversal */
template <typename T>
void printInOrder(const node_ptr<T>& node);

/* Template declaration for preOrder tree traversal */
template <typename T>
void printPreOrder(const node_ptr<T>& node);

/* Template declaration for postOrder tree traversal */
template <typename T>
void printPostOrder(const node_ptr<T>& node);

/* Template declaration for levelOrder tree traversal */
template <typename T>
void printLevelOrder(const node_ptr<T>& node);

template <typename T>
void printLevelOrderUtil(const node_ptr<T>& node, size_t level);

template <typename T>
size_t getHeight(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "PreOrder Traversal: ";
    printPreOrder(root);
    cout << "\nInOrder Traversal: ";
    printInOrder(root);
    cout << "\nPostOrder Traversal: ";
    printPostOrder(root);
    cout << "\nLevelOrder Traversal: ";
    printLevelOrder(root);

    return 0;
}

/* Template definition for inOrder tree traversal */
template <typename T>
void printInOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    printInOrder(node->left);
    cout << node->data << ' ';
    printInOrder(node->right);
}

/* Template definition for preOrder tree traversal */
template <typename T>
void printPreOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    cout << node->data << ' ';
    printPreOrder(node->left);
    printPreOrder(node->right);
}

/* Template definition for postOrder tree traversal */
template <typename T>
void printPostOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << ' ';
}

/* Template definition for levelOrder tree traversal */
template <typename T>
void printLevelOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    for(size_t index = 1; index <= getHeight(node); ++index)
        printLevelOrderUtil(node, index);
}

/* Level Order Traversal utilty function */
template <typename T>
void printLevelOrderUtil(const node_ptr<T>& node, size_t level) {
    if(!node)
        return;

    if(level == 1)
        cout << (node->data) << ' ';

    printLevelOrderUtil(node->left, level - 1);
    printLevelOrderUtil(node->right, level - 1);
}

/* Height of the tree - required by level order treversal */
template <typename T>
size_t getHeight(const node_ptr<T>& node) {
    if(!node)
        return 0;

    size_t ltreeHeight = 0, rtreeHeight = 0;

    if(node->left)
        ltreeHeight = getHeight(node->left);

    if(node->right)
        rtreeHeight = getHeight(node->right);

    if(ltreeHeight > rtreeHeight)
        return ltreeHeight + 1;
    else
        return rtreeHeight + 1;
}
