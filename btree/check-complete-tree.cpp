/* Check if the binary tree is complete or not */

#include <iostream>
#include <queue>
#include "tree.hpp"

using namespace std;

template <typename T>
bool checkCompleteTree(const node_ptr<T>& node);

int main(void) {
    auto const root = make_node<int>(1);
    root->left = make_node<int>(2);
    root->right = make_node<int>(3);
    root->left->left = make_node<int>(4);
    root->left->right = make_node<int>(5);
    root->right->left = make_node<int>(6);
    root->right->right = make_node<int>(7);

    cout << "Is binary tree complete? " << checkCompleteTree(root) << endl;

    return 0;
}

template <typename T>
bool checkCompleteTree(const node_ptr<T>& node) {
    if(!node)
        return true;

    queue<btNode<T>* > Q;
    Q.push(node.get());

    while(!Q.empty()) {
        btNode<T> *temp = Q.front();
        Q.pop();

        if(temp->right && !temp->left)
            return false;

        if(temp->left)
            Q.push((temp->left).get());

        if(temp->right)
            Q.push((temp->right).get());
    }

    return true;
}
