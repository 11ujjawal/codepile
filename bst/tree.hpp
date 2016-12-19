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
using node_ptr = std::shared_ptr<btNode<T>>;

/* Alias for a constant iterator to initializer_list */
template <typename T>
using iList = typename std::initializer_list<T>::const_iterator;

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
    return std::make_shared<btNode<T>>(value, std::move(lhs), std::move(rhs));
}

/* Function template for creating a binary search tree
 *
 * The function takes in input in the form of initializer_list, ordered in
 * ascending order. The middle element turns out to be the root element
 * and then a recursive call to the left half for the left element of root and
 * another recurvive call to the right half for the right element.
 *
 * Example -
 *
 * node_ptr<int> root = make_tree({1, 2, 3, 4, 5, 6, 7});
 *
 * The above statement will generate a tree of the form
 *
 *          4
 *         / \
 *        2   6
 *      / \  / \
 *     1  3 5  7
 *
 */
template <typename T>
node_ptr<T> make_tree(const std::initializer_list<T>& values, iList<T> begin, iList<T> end) {
    if(begin > end)
        return nullptr;

    auto mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);

    node_ptr<T> root = make_node(*mid);
    root->left = make(values, begin, std::prev(mid));
    root->right = make(values, std::next(mid), end);

    return root;
}

/* Template function to make a bst */
template <typename T>
auto make_bst(const std::initializer_list<T>& values) {
    return make_tree(values, values.begin(), std::prev(values.end()));
}

/* Level order tree traversal */
template <typename T>
void print(const node_ptr<T>& node) {
    if(!node)
        return;

    std::queue<btNode<T>* > Q;
    Q.push(node.get());

    while(!Q.empty()) {
        btNode<T> *temp = Q.front();
        Q.pop();

        std::cout << temp->data << ' ';

        if(temp->left)
            Q.push((temp->left).get());

        if(temp->right)
            Q.push((temp->right).get());
    }

    std::cout << std::endl;
}

#endif
