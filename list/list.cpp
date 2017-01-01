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

    auto head = make_list({2, 3, 3, 5, 6, 7, 7, 7, 8, 8, 9});
    print(head);

    /* Delete the duplicate elements */
    pop_dups(head);
    print(head);

    /* Delete kth node from end */
    pop_k_back(head, 2);
    print(head);

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

    /* check for a loop in the given list */
    auto iHead = make_list({3, 2, 5, 4});
    /* fetch the last node of the list above and make it's next pointer point to
     * the second node.
     */
    auto lastNode = fetch(iHead, length(iHead));
    lastNode->next = iHead->next;

    cout << "Is loop present in the list after the modification? " << loop(iHead) << endl;

    /* To check for intersection between two nodes, let the last node of iHead
     * point to the eighth node of head
     */
    lastNode->next = fetch(head, 8);
    auto iNode = intersection(iHead, head);
    cout << "Data at the intersection node: " << iNode->data << endl;

    swap(head, head, fetch(head, 5));
    print(head);
}

void checkIntOps() {
    cout << "\nChecking Integer Specific Operations" << endl;
    node_ptr<int> numOne = make_list({2, 4, 6, 8});
    node_ptr<int> numTwo = make_list({1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1});
    node_ptr<int> numThree = make_list({2, 3, 4, 1, 6, 5, 9, 8});

    /* Check whether the given lists are pallindrome or not */
    print(numOne);
    cout << "Is list pallindrome? " << pallindrome(numOne) << endl;
    print(numTwo);
    cout << "Is list pallindrome? " << pallindrome(numTwo) << endl;

    cout << "Sort given list in even odd" << endl;
    sortEvenOdd(numThree);
    print(numThree);
}

int main(void) {
    checkPush();
    checkPop();
    checkFind();
    checkUtility();
    checkIntOps();

    return 0;
}
