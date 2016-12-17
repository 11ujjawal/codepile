#ifndef _LIST_HPP
#define _LIST_HPP

#include <initializer_list>
#include <memory>

template <typename T>
struct node;

template <typename T>
using node_ptr = std::shared_ptr<node<T> >;

template <typename T>
struct node {
    T data;
    node_ptr<T> next;

    node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
auto make_node(const T& value) {
    return std::make_shared<node<T> >(value);
}

/* Given a reference to the list, insert a new node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key);

/* Given a reference to the list and a value, append the given value */
template <typename T>
void push_back(node_ptr<T>& head, const T& key);

/* Given a reference to the list, delete the node from the beginning of the list */
template <typename T>
void pop_front(node_ptr<T>& head);

/* Given a reference to a list, delete the node from the end */
template <typename T>
void pop_back(node_ptr<T>& head);

/* Given a reference to the list, print the values in the list */
template <typename T>
void print(const node_ptr<T>& head);

#endif
