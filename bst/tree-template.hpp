/*
 * The below template for tree has been written by TemplateRex in stackoverflow
 * http://stackoverflow.com/a/32602486/3724822
 */

#include <memory>
#include <utility>

template <typename T>
struct btNode;

template <typename T>
using node_ptr = std::unique_ptr<btNode<T>>;

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
    return std::make_unique<btNode<T>>(value, std::move(lhs), std::move(rhs));
}
