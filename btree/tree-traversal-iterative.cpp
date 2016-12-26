/* Iteratively traverse the binary tree */

#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include "tree.hpp"

using namespace std;

template <typename T>
void printPreOrder(const node_ptr<T>& node);

template <typename T>
void printInOrder(const node_ptr<T>& node);

template <typename T>
void printPostOrder(const node_ptr<T>& node);

template <typename T>
void printLevelOrder(const node_ptr<T>& node);

int main(void) {
    auto const root = make_tree({1, 2, 3, 4, 5, 6, 7});

    cout << "PreOrder Traversal: ";
    printPreOrder(root);
    cout << "InOrder Traversal: ";
    printInOrder(root);
    cout << "PostOrder Traversal: ";
    printPostOrder(root);
    cout << "LevelOrder Traversal: ";
    printLevelOrder(root);
    cout << endl;

    return 0;
}

template <typename T>
void printPreOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    stack<btNode<T>* > Stack;
    Stack.push(node.get());

    while(!Stack.empty()) {
        btNode<T> *temp = Stack.top();
        Stack.pop();

        cout << temp->data << ' ';

        if(temp->right)
            Stack.push((temp->right).get());

        if(temp->left)
            Stack.push((temp->left).get());
    }

    cout << endl;
}

template <typename T>
void printInOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    stack<btNode<T>* > Stack;
    btNode<T> *currNode = node.get();

    while(currNode) {
        Stack.push(currNode);
        currNode = currNode->left.get();
    }

    while(!Stack.empty()) {
        currNode = Stack.top();
        Stack.pop();

        cout << (currNode->data) << ' ';

        if(currNode->right)
            Stack.push(currNode->right.get());
    }

    cout << endl;
}

template <typename T>
void printPostOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    btNode<T> *prevNode = nullptr, *currNode;

    stack<btNode<T>* > Stack;
    Stack.push(node.get());

    while(!Stack.empty()) {
        currNode = Stack.top();

        if(!prevNode || prevNode->left.get() == currNode || prevNode->right.get() == currNode) {
            if(currNode->left)
                Stack.push(currNode->left.get());
            else if(currNode->right)
                Stack.push(currNode->right.get());
        } else if(currNode->left.get() == prevNode) {
            if(currNode->right)
                Stack.push(currNode->right.get());
        } else {
            cout << (currNode->data) << ' ';
            Stack.pop();
        }

        prevNode = currNode;
    }

    cout << endl;
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
