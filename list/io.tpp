#include <iostream>

/* Given a reference to the list, print the values in the list */
template <typename T>
void print(const node_ptr<T>& head) {

    if(head) {
        node_ptr<T> iter = head;
        while(iter != nullptr) {
            std::cout << iter->data << " -> ";
            iter = iter->next;
        }
    }

    std::cout << "nullptr" << std::endl;
}

/* Given a reference to a list, print it in reverse order */
template <typename T>
void printReverse(const node_ptr<T>& head) {
    if(!head) {
        std::cout << "nullptr";
        return;
    }

    printReverse(head->next);

    std::cout << " <- " << head->data;
}
