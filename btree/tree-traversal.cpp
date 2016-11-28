/* Tree traversal in binary tree */

#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

/* Template declaration for inOrder tree traversal */
template <typename T>
void printInOrder(btNode<T> const& node);

/* Template declaration for preOrder tree traversal */
template <typename T>
void printPreOrder(btNode<T> const& node);

/* Template declaration for postOrder tree traversal */
template <typename T>
void printPostOrder(btNode<T> const& node);


int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "PreOrder Traversal: ";
    printPreOrder(*root);
    cout << "\nInOrder Traversal: ";
    printInOrder(*root);
    cout << "\nPostOrder Traversal: ";
    printPostOrder(*root);
    cout << endl;

    return 0;
}

/* Template definition for inOrder tree traversal */
template <typename T>
void printInOrder(btNode<T> const& node) {
    if(node.left)
        printInOrder(*node.left);

    cout << node.data << ' ';

    if(node.right)
        printInOrder(*node.right);
}

/* Template definition for preOrder tree traversal */
template <typename T>
void printPreOrder(btNode<T> const& node) {
    cout << node.data << ' ';

    if(node.left)
        printInOrder(*node.left);

    if(node.right)
        printInOrder(*node.right);
}

/* Template definition for postOrder tree traversal */
template <typename T>
void printPostOrder(btNode<T> const& node) {
    if(node.left)
        printInOrder(*node.left);

    if(node.right)
        printInOrder(*node.right);

    cout << node.data << ' ';
}
