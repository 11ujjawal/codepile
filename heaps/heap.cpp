/* Demonstration of heap data structure */

#include <iostream>
#include "heap.hpp"

using namespace std;

int main(void) {
    heap<int> hOne{3, 2, 6, 5, 8, 7, 1};

    /* Initial structure of heap */
    hOne.print();

    /* Fetch the minimum element */
    cout << "Minimum element: " << hOne.getMin() << endl;

    /* Add new elements and extract the old ones */
    hOne.extractMin();
    hOne.insert(4);
    hOne.insert(0);
    hOne.print();
    cout << "Minimum element: " << hOne.getMin() << endl;

    hOne.remove(3);
    hOne.decreaseKey(5, 1);
    hOne.print();

    auto sortedElem = hOne.sort();
    for(auto elem : sortedElem)
        cout << elem << ' ';
    cout << endl;


    return 0;
}
