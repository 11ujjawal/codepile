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

/* ---------------------------------------------------------------------------
 * Data insertion operations
 * push_front()
 * push_back()
 * push_at()
 * push_sorted()
 */

/* Given a reference to the list, insert a new node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key);

/* Given a reference to the list and a value, append the given value */
template <typename T>
void push_back(node_ptr<T>& head, const T& key);

/* Given a reference to a node in the list, insert a new node after the given
 * node reference
 */
template <typename T>
void push_at(node_ptr<T>& node, const T& key);

/* Given a reference to a sorted list, insert a new node */
template <typename T>
void push_sorted(node_ptr<T>& head, const T& key);

/* Template implementation */
#include "push.tpp"

/* ---------------------------------------------------------------------------
 * Data deletion operations
 * pop_front()
 * pop_back()
 * pop_at()
 * pop_all()
 */

/* Given a reference to the list, delete the first node */
template <typename T>
void pop_front(node_ptr<T>& head);

/* Given a reference to a list, delete the node from the end */
template <typename T>
void pop_back(node_ptr<T>& head);

/* Given a reference to a node, delete the node after it */
template <typename T>
void pop_at(node_ptr<T>& node);

/* Given a reference to a node, delete the list */
template <typename T>
void pop_all(node_ptr<T>& node);

/* Template implementation */
#include "pop.tpp"

/* ---------------------------------------------------------------------------
 * Data search operations
 * search()
 * find() - similar to search(), follows a recursive approach
 * fetch()
 * fetchMid()
 */

/* Given a reference to the head of the list and a key, check for the key -
 * iterative method
 */
template <typename T>
bool search(const node_ptr<T>& head, const T& key);

/* Given a reference to the head of the list and a key, check for the key -
 * recursive method
 */
template <typename T>
bool find(const node_ptr<T>& head, const T& key);

/* Given a reference to a list, fetch the nth node of a list */
template <typename T>
node_ptr<T> fetch(const node_ptr<T>& head, const size_t index);

/* Given a reference to a list, find the middle node */
template <typename T>
node_ptr<T> fetchMid(const node_ptr<T>& head);

/* Template implementation */
#include "find.tpp"

/* ---------------------------------------------------------------------------
 * Utility operations
 * fetchNodeCount()
 * loop()
 * length()
 * reverse()
 */

/* Given a reference to a list and an element, fetch the count of element
 * occurrence in list
 */
template <typename T>
size_t fetchNodeCount(const node_ptr<T>& head, const T& key);

/* Given a reference to a list, detect loop in the list */
template <typename T>
bool loop(const node_ptr<T>& head);

/* Given references to two lists, merge them */
template <typename T>
void merge(node_ptr<T>& headOne, node_ptr<T>& headTwo);

/* Given a reference to the head of a list, fetch the length */
template <typename T>
size_t length(const node_ptr<T>& head);

/* Given a pointer to the head of list, reverse the list */
template <typename T>
void reverse(node_ptr<T>& head);

/* Template implementation */
#include "utility.tpp"

/* ---------------------------------------------------------------------------
 * IO operations
 * print()
 */

/* Given a reference to the list, print the values in the list */
template <typename T>
void print(const node_ptr<T>& head);

/* Template implementation */
#include "io.tpp"

#endif
