/* Basic operation in linked list */

#include <iostream>
#include "list.hpp"

using namespace std;

int main(void) {
    /* Create a pointer to a node template, currently pointing to 'nullptr' */
    node_ptr<int> head = nullptr;

    /* Insert a node at the start of the list */
    push_front(head, 10);
    print(head);

    /* Insert a node at the end of the list */
    push_back(head, 30);
    print(head);

    /* Insert a node after the first node */
    push_at(head, 100);
    print(head);

    /* Fetch the length of the list */
    cout << "\nThe list has " << length(head) << " nodes." << endl;

    /* Check if a value is present in the list */
    cout << "Is the value 30 present in the list? " << search(head, 30) << endl;

    /* Check if a value is present in the list */
    cout << "Is the value 50 present in the list? " << find(head, 50) << endl;

    /* Delete the second node */
    pop_at(head);
    print(head);

    /* Delete a node from the start */
    pop_front(head);
    print(head);

    /* Delete a node from the end */
    pop_back(head);
    print(head);

    auto listHead = make_list({1, 2, 3, 4});
    print(reverse(listHead));

    return 0;
}

/* Given a reference to the list, insert a new node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key) {
    if(!head) {
        head = make_node(key);
        return;
    }

    node_ptr<T> temp = make_node(key);
    temp->next = head;
    head = temp;
}

/* Given a reference to the list and a value, append the given value */
template <typename T>
void push_back(node_ptr<T>& head, const T& key) {
    if(!head) {
        head = make_node(key);
        return;
    }

    node_ptr<T> counter = head;
    while(counter->next != nullptr)
        counter = counter->next;

    counter->next = make_node(key);
}

/* Given a reference to a node in the list, insert a new node after the given node reference */
template <typename T>
void push_at(node_ptr<T>& node, const T& key) {
    if(!node)
        return;

    node_ptr<T> temp = make_node(key);
    temp->next = node->next;
    node->next = temp;
}

/* Given a reference to the list, delete the node from the beginning of the list */
template <typename T>
void pop_front(node_ptr<T>& head) {
    if(!head)
        return;

    node_ptr<T> temp = head;
    head = head->next;
}

/* Given a reference to a list, delete the node from the end */
template <typename T>
void pop_back(node_ptr<T>& head) {
    if(!head)
        return;

    if(head->next == nullptr) {
        head = nullptr;
        return;
    }

    node_ptr<T> iter = head;
    while(iter->next->next != nullptr)
        iter = iter->next;

    iter->next = nullptr;
}

/* Given a reference to a node, delete the node after it */
template <typename T>
void pop_at(node_ptr<T>& node) {
    if(!node && !node->next)
        return;

    node->next = node->next->next;
}

/* Given a reference to the list, print the values in the list */
template <typename T>
void print(const node_ptr<T>& head) {

    if(head) {
        node_ptr<T> iter = head;
        while(iter != nullptr) {
            cout << iter->data << " -> ";
            iter = iter->next;
        }
    }

    cout << "nullptr" << endl;
}

/* Given a reference to the head of a list, fetch the length */
template <typename T>
size_t length(const node_ptr<T>& head) {
    size_t counter = 0;
    node_ptr<T> iter = head;

    while(iter != nullptr) {
        counter++;
        iter = iter->next;
    }

    return counter;
}

/* Given a reference to the head of the list and a key, check for the key */
template <typename T>
bool search(const node_ptr<T>& head, const T& key) {
    node_ptr<T> iter = head;

    while(iter != nullptr) {
        if(iter->data == key)
            return true;

        iter = iter->next;
    }

    return false;
}

/* Given a reference to the head of the list and a key, check for the key */
template <typename T>
bool find(const node_ptr<T>& head, const T& key) {
    if(!head)
        return false;

    if(head->data == key)
        return true;

    return find(head->next, key);
}

// /* Given reference to two nodes in the list, swap the nodes */
// template <typename T>
// void swap(const node_ptr<T>& head, node_ptr<T>& nodeOne, node_ptr<T>& nodeTwo) {
//     if(!nodeOne && !nodeTwo)
//         return;
//
//     node_ptr<T> iter = head;
//
//     if(nodeOne == head) {
//         while(iter->next != nullptr) {
//             if
//         }
//     }
// }

/* Given a pointer to the head of list, reverse the list */
template <typename T>
node_ptr<T> reverse(node_ptr<T> head) {
    if(!head)
        return nullptr;

    node_ptr<T> nextNode, currNode, prevNode;
    prevNode = nullptr;
    currNode = head;

    while(currNode) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}
