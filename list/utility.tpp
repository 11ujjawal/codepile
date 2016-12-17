/* Given a reference to a list and an element, fetch the count of element occurrence in list */
template <typename T>
size_t fetchNodeCount(const node_ptr<T>& head, const T& key) {
    if(!head)
        return 0;

    size_t counter = 0;
    node_ptr<T> iter = head;
    while(iter) {
        if(iter->data == key)
            counter++;
        iter = iter->next;
    }

    return counter;
}

/* Given a pointer to the head of list, reverse the list */
template <typename T>
void reverse(node_ptr<T>& head) {
    if(!head)
        return;

    node_ptr<T> nextNode, currNode, prevNode;
    prevNode = nullptr;
    currNode = head;

    while(currNode) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    head = prevNode;
}

/* Given a reference to the head of a list, fetch the length */
template <typename T>
size_t length(const node_ptr<T>& head) {
    size_t counter = 0;
    node_ptr<T> iter = head;

    while(iter != nullptr) {
        counter++;
        iter = iter->next;
    }

    return counter;
}

/* Given a reference to a list, detect loop in the list */
template <typename T>
bool loop(const node_ptr<T>& head) {
    if(!head)
        return false;

    node_ptr<T> fastIter, slowIter;
    fastIter = slowIter = head;

    while(fastIter && fastIter->next) {
        fastIter = fastIter->next->next;
        slowIter = slowIter->next;

        if(slowIter == fastIter)
            return true;
    }

    return false;
}
