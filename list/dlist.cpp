#include <iostream>
#include "dlist.hpp"

using namespace std;

/* Check push operations in dll */
void checkPush() {
    cout << "\nPush elementd into list" << endl;
    node_ptr<int> head = nullptr;

    push_front(head, 10);
    print(head);

    push_back(head, 30);
    print(head);

    push_after(head->next, 40);
    print(head);

    push_before(head->next->next, 20);
    print(head);
}

/* Check pop operations in dll */
void checkPop() {
    cout << "\nPop elementd from list" << endl;
    node_ptr<int> head = make_list<int>({1, 2, 3, 4, 5, 6});

    pop_front(head);
    print(head);

    pop_back(head);
    print(head);

    pop_after(head->next);
    print(head);
}

int main(void) {
    checkPush();
    checkPop();

    /* Reverse a coubly linked list */
    node_ptr<int> head = make_list({1, 2, 3, 4, 5, 6});
    reverse(head);
    print(head);

    return 0;
}
