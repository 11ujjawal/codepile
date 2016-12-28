/* Fetch the diameter to the given tree */

#include <iostream>
#include "tree.hpp"

using namespace std;

/* Fetch the diameter of the given tree */
template <typename T>
size_t getDiameter(const node_ptr<T>& node);

/* Fetch the height of the given tree */
template <typename T>
size_t getHeight(const node_ptr<T>& node);

/* Fetch the size of the given tree */
template <typename T>
size_t getSize(const node_ptr<T>& node);

int main(void) {
    auto const root = make_tree({1, 2, 3, 4, 5, 6, 7});

    cout << "Diameter: " << getDiameter(root) << endl;
    cout << "Height: " << getHeight(root) << endl;
    cout << "Size: " << getSize(root) << endl;

    return 0;
}

/* Maximum number of nodes from left to right */
template <typename T>
size_t getDiameter(const node_ptr<T>& node) {
    if(!node)
        return 0;

    size_t lheight = getHeight(node->left), rheight = getHeight(node->right);

    return max(lheight + rheight + 1, max(getDiameter(node->left), getDiameter(node->right)));
}

/* Get the maximum number of nodes on the path from the given node to a leaf */
template <typename T>
size_t getHeight(const node_ptr<T>& node) {
    if(!node)
        return 0;

    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

/* Get the total number of nodes in the subtree with the given node as root */
template <typename T>
size_t getSize(const node_ptr<T>& node) {
    if(!node)
        return 0;

    return 1 + getSize(node->left) + getSize(node->right);
}
