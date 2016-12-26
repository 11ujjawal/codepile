/* Print the tree in spiral order */

#include <iostream>
#include <stack>
#include "tree.hpp"

using namespace std;

template <typename T>
void printSpiralOrderIter(const node_ptr<T>& node);

template <typename T>
void printSpiralOrder(const node_ptr<T>& node);

template <typename T>
void printSpiralOrderUtil(const node_ptr<T>& node, size_t index, bool ltr);

template <typename T>
size_t getHeight(const node_ptr<T>& node);

int main(void) {
    auto const root = make_tree<double>({1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0});

    cout << "Tree in spiral order (Recursive method): ";
    printSpiralOrder(root);

    cout << "Tree in spiral order (Iterative method): ";
    printSpiralOrderIter(root);

    return 0;
}

/* For spiral level order traversal using iteration, traverse one level storing
 * the left node first and then the right node and for the alternate iteration
 * store the right node first and then the left node. Use a boolean flag
 * to store the current traversal direction.
 */
template <typename T>
void printSpiralOrder(const node_ptr<T>& node) {
    if(!node)
        return;

    bool ltr = false;
    for(size_t index = 1; index <= getHeight(node); ++index) {
        printSpiralOrderUtil(node, index, ltr);
        ltr = !ltr;
    }

    cout << endl;
}

template <typename T>
void printSpiralOrderUtil(const node_ptr<T>& node, size_t index, bool ltr) {
    if(!node)
        return;

    if(index == 1)
        cout << (node->data) << ' ';

    if(ltr) {
        printSpiralOrderUtil(node->left, index - 1, ltr);
        printSpiralOrderUtil(node->right, index - 1, ltr);
    } else {
        printSpiralOrderUtil(node->right, index - 1, ltr);
        printSpiralOrderUtil(node->left, index - 1, ltr);
    }
}

/* For printing tree in level order spiral form, use two stacks, one for
 * traversing left to right at a level and the other for traversing right
 * to left
 */
template <typename T>
void printSpiralOrderIter(const node_ptr<T>& node) {
    if(!node)
        return;

    stack<btNode<T>* > StackOne, StackTwo;
    StackOne.push(node.get());

    while(!StackOne.empty() || !StackTwo.empty()) {

        while(!StackOne.empty()) {
            btNode<T> *currNode = StackOne.top();
            StackOne.pop();

            cout << (currNode->data) << ' ';

            if(currNode->right)
                StackTwo.push(currNode->right.get());
            if(currNode->left)
                StackTwo.push(currNode->left.get());
        }

        while(!StackTwo.empty()) {
            btNode<T> *currNode = StackTwo.top();
            StackTwo.pop();

            cout << (currNode->data) << ' ';

            if(currNode->left)
                StackOne.push(currNode->left.get());
            if(currNode->right)
                StackOne.push(currNode->right.get());
        }
    }

    cout << endl;
}

template <typename T>
size_t getHeight(const node_ptr<T>& node) {
    if(!node)
        return 0;

    size_t leftHeight = getHeight(node->left);
    size_t rightHeight = getHeight(node->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
