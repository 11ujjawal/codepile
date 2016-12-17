#ifndef _LIST_HPP
#define _LIST_HPP

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
    node_ptr<T> next;

    node(const T& value) : data(value), next(nullptr) {}
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
        temp = temp->next;
    }

    return head;
}

/* Given a reference to the list, insert a new node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key);

/* Given a reference to the list and a value, append the given value */
template <typename T>
void push_back(node_ptr<T>& head, const T& key);

/* Given a reference to a node in the list, insert a new node after the given node reference */
template <typename T>
void push_at(node_ptr<T>& node, const T& key);

/* Given a reference to the list, delete the node from the beginning of the list */
template <typename T>
void pop_front(node_ptr<T>& head);

/* Given a reference to a list, delete the node from the end */
template <typename T>
void pop_back(node_ptr<T>& head);

/* Given a reference to a node, delete the node after it */
template <typename T>
void pop_at(node_ptr<T>& node);

/* Given a reference to the head of a list, fetch the length */
template <typename T>
size_t length(const node_ptr<T>& head);

/* Given a reference to the head of the list and a key, check for the key - iterative method */
template <typename T>
bool search(const node_ptr<T>& head, const T& key);

/* Given a reference to the head of the list and a key, check for the key - recursive method */
template <typename T>
bool find(const node_ptr<T>& head, const T& key);

// /* Given reference to two nodes in the list, swap the nodes */
// template <typename T>
// void swap(node_ptr<T>& nodeOne, node_ptr<T>& nodeTwo);

/* Given a pointer to the head of list, reverse the list */
template <typename T>
node_ptr<T> reverse(node_ptr<T> head);

/* Given a reference to the list, print the values in the list */
template <typename T>
void print(const node_ptr<T>& head);

#endif
