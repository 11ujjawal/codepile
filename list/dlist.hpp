#ifndef _DLIST_HPP
#define _DLIST_HPP

#include <initializer_list>
#include <memory>

/* Declaring the node data structure */
template <typename T>
struct node;

/* Defining an alias for shared pointer to node */
template <typename T>
using node_ptr = std::shared_ptr<node<T> >;

/* Defining the node data structure */
template <typename T>
struct node {
    T data;
    node_ptr<T> prev, next;

    node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

/* Method to make an object of the node data structure */
template <typename T>
auto make_node(const T& value) {
    return std::make_shared<node<T> >(value);
}

/* Method to make an object to multiple node data structure - a list */
template <typename T>
auto make_list(const std::initializer_list<T>& values) {
    typename std::initializer_list<T>::iterator iter = values.begin();

    node_ptr<T> temp, head;
    temp = head = make_node(*iter);
    iter++;

    for(; iter != values.end(); ++iter) {
        temp->next = make_node(*iter);
        temp->next->prev = temp;
        temp = temp->next;
    }

    return head;
}

/* Given a reference to the head of a doubly linked list, insert a node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key);

/* Given a reference to the head of a doubly linked list, insert a node at the end */
template <typename T>
void push_back(node_ptr<T>& head, const T& key);

/* Given a reference to a node of a doubly linked list, insert a node after the given node */
template <typename T>
void push_after(node_ptr<T>& head, const T& key);

/* Given a reference to a node of a doubly linked list, insert a node before the given node */
template <typename T>
void push_before(node_ptr<T>& head, const T& key);

/* Given a reference to the head of a doubly linked list, remove the first node */
template <typename T>
void pop_front(node_ptr<T>& head);

/* Given a reference to the head of a doubly linked list, remove the list node */
template <typename T>
void pop_back(node_ptr<T>& head);

/* Given a reference to a node of a doubly linked list, remove the node after the given node */
template <typename T>
void pop_after(node_ptr<T>& head);

/* Reverse a doubly linked list */
template <typename T>
void reverse(node_ptr<T>& head);

/* Print the content of a doubly linked list */
template <typename T>
void print(const node_ptr<T>& head);

template <typename T>
void printReverse(const node_ptr<T>& head);

#include "dlist.tpp"

#endif
