/* Basic operation in linked list */

#include <iostream>
#include "list.hpp"

using namespace std;

int main(void) {
    /* Create a pointer to a node template, currently pointing to 'nullptr' */
    node_ptr<int> head = nullptr;

    /* Insert a node at the start of the list */
    push_front(head, 10);
    print(head);

    /* Insert a node at the end of the list */
    push_back(head, 30);
    print(head);

    /* Insert a node after the first node */
    push_at(head, 100);
    print(head);

    /* Fetch the length of the list */
    cout << "\nThe list has " << length(head) << " nodes." << endl;

    /* Check if a value is present in the list */
    cout << "Is the value 30 present in the list? " << search(head, 30) << endl;

    /* Check if a value is present in the list */
    cout << "Is the value 50 present in the list? " << find(head, 50) << endl;

    /* Delete the second node */
    pop_at(head);
    print(head);

    /* Delete a node from the start */
    pop_front(head);
    print(head);

    /* Delete a node from the end */
    pop_back(head);
    print(head);

    auto listHead = make_list({1, 2, 3, 4, 5, 6, 7, 8});
    reverse(listHead);
    print(listHead);

    if(auto nodeThree = fetch(listHead, 3))
        cout << "3rd node has the value : " << nodeThree->data << endl;

    cout << "Middle node of the list has the value : " << fetchMid(listHead)->data << endl;

    auto listOne = make_list({2, 3, 1, 3, 3, 5, 7, 4, 2, 4, 3, 8, 6, 3});
    cout << "The element 3 occurrs " << fetchNodeCount(listOne, 3) << " times in the list" << endl;

    auto listTwo = make_list({2, 4, 1, 6, 5});
    listTwo->next->next->next->next->next = listTwo->next;
    cout << "Does loop exists? " << loop(listOne) << endl;
    cout << "Does loop exists? " << loop(listTwo) << endl;

    auto listSorted = make_list({2, 4, 6, 8, 9});
    push_sorted(listSorted, 7);
    push_sorted(listSorted, 1);
    print(listSorted);

    return 0;
}
