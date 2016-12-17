/* Template implementation of linked list */

#include <iostream>
#include "list.hpp"

using namespace std;


/* Check the push operations of template list implementation */
void checkPush() {
    cout << "\nChecking Push Operations" << endl;

    /* Create a pointer to a node template, currently pointing to 'nullptr' */
    node_ptr<int> head = nullptr;

    /* Insert a node at the start of the list */
    push_front(head, 1);
    print(head);

    /* Insert a node at the end of the list */
    push_back(head, 3);
    print(head);

    /* Insert a node after the first node */
    push_at(head, 10);
    print(head);
}


/* Check the pop operations of template list implementation */
void checkPop() {
    cout << "\nChecking Pop Operations" << endl;

    auto head = make_list({2, 3, 6, 8, 1});

    /* Delete the third node */
    pop_at(head->next);
    print(head);

    /* Delete a node from the start */
    pop_front(head);
    print(head);

    /* Delete a node from the end */
    pop_back(head);
    print(head);
}


/* Check the find operations of template list implementation */
void checkFind() {
    cout << "\nChecking Find Operations" << endl;

    auto head = make_list({1, 4, 2, 6, 7, 5, 8});
    print(head);

    /* Check if a value is present in the list */
    cout << "Is the value 6 present in the list? " << search(head, 6) << endl;

    /* Check if a value is present in the list */
    cout << "Is the value 50 present in the list? " << find(head, 50) << endl;

    /* Fetch the 5th element */
    if(auto nNode = fetch(head, 5))
        cout << "The value of 5th element is " << nNode->data << endl;

    /* Fetch the middle element */
    if(auto midNode = fetchMid(head))
        cout << "The middle element is " << midNode->data << endl;
}


/* Check the utility operations of template list implementation */
void checkUtility() {
    cout << "\nChecking Utility Operations" << endl;

    auto head = make_list({2, 3, 1, 3, 3, 5, 7, 4, 2, 4, 3, 8, 6, 3});
    print(head);

    /* Fetch the length of the list */
    cout << "The list has " << length(head) << " nodes." << endl;

    cout << "The element 3 occurrs " << fetchNodeCount(head, 3) << " times in the list" << endl;

    /* Reverse the list */
    cout << "Reversed list: " << endl;
    reverse(head);
    print(head);
}


int main(void) {
    checkPush();
    checkPop();
    checkFind();
    checkUtility();

    return 0;
}
