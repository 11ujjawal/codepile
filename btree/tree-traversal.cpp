/* Tree traversal in binary tree */

#include <iostream>
#include <queue>
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

/* Tempplate declaration for levelOrder traversal */
template <typename T>
void printLevelOrder(const node_ptr<T>& node);


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

/* Tempplate definition for levelOrder traversal */
template <typename T>
void printLevelOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    queue<btNode<T>* > Q;
    Q.push(node.get());

    while(!Q.empty()) {
        btNode<T> *temp = Q.front();
        Q.pop();

        cout << temp->data << ' ';

        if(temp->left != nullptr)
            Q.push((temp->left).get());

        if(temp->right != nullptr)
            Q.push((temp->right).get());
    }

    cout << endl;
}
