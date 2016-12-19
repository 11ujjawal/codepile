#include <iostream>
#include "tree.hpp"

using namespace std;

int main(void) {
    node_ptr<int> root = make_tree({2, 3, 4, 5, 6, 1, 4, 9, 0});
    print(root);

    auto node = make_bst({1, 2, 3, 4, 5, 6, 7});
    print(node);

    return 0;
}
