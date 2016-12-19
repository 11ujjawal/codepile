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

template <typename T>
struct btNode;

template <typename T>
using node_ptr = std::shared_ptr<btNode<T>>;

template <typename T>
struct btNode {
    T data;
    node_ptr<T> left, right;

    btNode(T const &key, node_ptr<T> lhs, node_ptr<T> rhs)
     :
        data(key), left(std::move(lhs)), right(std::move(rhs))
    {}
};

template <typename T>
auto make_node(T const &value, node_ptr<T> lhs = nullptr, node_ptr<T> rhs = nullptr) {
    return std::make_shared<btNode<T>>(value, std::move(lhs), std::move(rhs));
}

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

        if(iter) {
            node->right = make_node(*iter);
            Q.push(node->right.get());
            iter++;
        }
    }

    return root;
}

template <typename T>
auto make_bst(const std::initializer_list<T>& values) {

}

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
