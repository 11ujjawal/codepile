/* Binary Search Tree implementation */

#include <iostream>
#include <string>
#include "bst.hpp"

int main(void) {
    /* BST for integers as data */
    bst<int> btree;
    btree.insert(10);
    btree.insert(80);
    btree.insert(30);
    btree.insert(20);

    std::cout << "Searching in BST ---> \n";
    std::cout << "Find 20: " << btree.find(20) << "\nFind 25: " << btree.find(25) << std::endl;
    auto min = btree.min();
    if(min)
        std::cout << *min << std::endl;

    /* BST for strings as data */
    bst<std::string> strBt;
    strBt.insert(std::string("tree"));
    strBt.insert(std::string("new tree"));

    std::cout << "Find 'new tree': " << strBt.find(std::string("new tree")) << std::endl;
    std::cout << "Find 'next tree': " << strBt.find(std::string("next tree")) << std::endl;

    return 0;
}
