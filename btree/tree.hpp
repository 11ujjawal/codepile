/*
 * The below template for tree has been written by TemplateRex in stackoverflow
 * http://stackoverflow.com/a/32602486/3724822
 */

#ifndef _TREE_HPP
#define _TREE_HPP

#include <memory>
#include <utility>
#include <queue>
#include <initializer_list>

/* btNode - Binary Search Tree node declaration */
template <typename T>
struct btNode;

/* Alias for a shared pointer to a BST node */
template <typename T>
using node_ptr = std::unique_ptr<btNode<T>>;

/* BST node definition */
template <typename T>
struct btNode {
    T data;
    node_ptr<T> left, right;

    btNode(T const &key, node_ptr<T> lhs, node_ptr<T> rhs)
     :
        data(key), left(std::move(lhs)), right(std::move(rhs))
    {}
};

/* Function template for initiaizing a new node of btNode type */
template <typename T>
auto make_node(T const &value, node_ptr<T> lhs = nullptr, node_ptr<T> rhs = nullptr) {
    return std::make_unique<btNode<T>>(value, std::move(lhs), std::move(rhs));
}

/* Function template for creating a binary tree
 *
 * The function takes in input in the form of initializer_list. The list has
 * values of tree nodes in level order. These values are then attached to build
 * a tree, in level order form.
 *
 * Example -
 *
 * node_ptr<int> root = make_tree({1, 2, 3, 4, 5, 6, 7});
 *
 * The above statement will generate a tree of the form
 *
 *          1
 *         / \
 *        2   3
 *      / \  / \
 *     4  5 6  7
 *
 */
template <typename T>
auto make_tree(const std::initializer_list<T>& values) {
    typename std::initializer_list<T>::const_iterator iter = values.begin();
    node_ptr<T> root = make_node(*iter);
    iter++;

    std::queue<btNode<T>* > Q;
    Q.push(root.get());

    while(iter != values.end()) {
        btNode<T> *node = Q.front();
        Q.pop();

        node->left = make_node(*iter);
        Q.push(node->left.get());
        iter++;

        if(iter != values.end()) {
            node->right = make_node(*iter);
            Q.push(node->right.get());
            iter++;
        }
    }

    return root;
}

#endif
