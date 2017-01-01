/* Doubly Linke List template implementation */

/* Given a reference to the head of a doubly linked list, insert a node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key) {
    node_ptr<T> newNode = make_node<T>(key);

    newNode->next = head;
    if(head)
        head->prev = newNode;
    head = newNode;
}

/* Given a reference to the head of a doubly linked list, insert a node at the end */
template <typename T>
void push_back(node_ptr<T>& head, const T& key) {
    node_ptr<T> iter = head;

    while(iter->next != nullptr)
        iter = iter->next;

    iter->next = make_node<T>(key);
    iter->next->prev = iter;
}

/* Given a reference to a node of a doubly linked list, insert a node after the given node */
template <typename T>
void push_after(node_ptr<T>& head, const T& key) {
    node_ptr<T> newNode = make_node<T>(key);

    newNode->next = head->next;
    newNode->prev = head;

    if(head->next)
        head->next->prev = newNode;

    head->next = newNode;
}

/* Given a reference to a node of a doubly linked list, insert a node before the given node */
template <typename T>
void push_before(node_ptr<T>& head, const T& key) {
    node_ptr<T> newNode = make_node<T>(key);

    newNode->next = head;
    newNode->prev = head->prev;

    if(head->prev)
        head->prev->next = newNode;

    head->prev = newNode;
}

/* Given a reference to the head of a doubly linked list, remove the first node */
template <typename T>
void pop_front(node_ptr<T>& head) {
    if(!head)
        return;

    head->next->prev = nullptr;
    head = head->next;
}

/* Given a reference to the head of a doubly linked list, remove the list node */
template <typename T>
void pop_back(node_ptr<T>& head) {
    if(!head)
        return;

    if(!head->next)
        head = nullptr;

    node_ptr<T> iter = head;
    while(iter->next->next != nullptr)
        iter = iter->next;

    iter->next = nullptr;
}

/* Given a reference to a node of a doubly linked list, remove the node after the given node */
template <typename T>
void pop_after(node_ptr<T>& head) {
    if(!head)
        return;

    if(head->next) {
        if(head->next->next)
            head->next->next->prev = head;

        head->next = head->next->next;
    }
}

/* Reverse a doubly linked list */
template <typename T>
void reverse(node_ptr<T>& head) {
    node_ptr<T> currNode = head, prevNode = nullptr, nextNode;

    while(currNode) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nullptr;

        if(prevNode)
            prevNode->prev = currNode;

        prevNode = currNode;
        currNode = nextNode;
    }

    head = prevNode;
}

/* Print the elements in a doubly linked list */
template <typename T>
void print(const node_ptr<T>& head) {
    node_ptr<T> iter = head;

    while(iter) {
        std::cout << iter->data << " <=> ";
        iter = iter->next;
    }

    std::cout << " nullptr " << std::endl;
}

/* Print the contents of a doubly linked list in reverse order */
template <typename T>
void printReverse(const node_ptr<T>& head) {
    node_ptr<T> iter = head;

    while(iter->next)
        iter = iter->next;

    while(iter) {
        std::cout << iter->data << " <=> ";
        iter = iter->prev;
    }

    std::cout << " nullptr " << std::endl;
}
