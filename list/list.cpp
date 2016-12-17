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

    /* Delete a node from the start */
    pop_front(head);
    print(head);

    /* Delete a node from the end */
    pop_back(head);
    print(head);

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
