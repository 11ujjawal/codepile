#include <iostream>
#include "qarray.hpp"

int main(void) {
    /* Create a new object of qArray, passing in the data type and the array size */
    qArray<int, 8> qa;

    /* Insert and remove elements using the push() and pop() */
    qa.push(20);
    qa.push(90);
    qa.pop();
    qa.push(40);
    qa.push(82);

    std::cout << "First element: " << qa.front() << std::endl;
    std::cout << "Last element: " << qa.back() << std::endl;
    std::cout << "Total number of elements: " << qa.size() << std::endl;

    /* Use subscript operator to assign and fetch values */
    qa[0] = 30;
    std::cout << qa[0] << std::endl;

    return 0;
}
