#include <iostream>
#include "tree.hpp"

using namespace std;

int main(void) {
    auto root = make_tree({2, 3, 4, 5, 6, 1, 4, 9, 0});
    print(root);
    
    return 0;
}
