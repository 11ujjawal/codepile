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

/* Given references to two lists, find their intersection point */
template <typename T>
node_ptr<T> intersection(const node_ptr<T>& headOne, const node_ptr<T>& headTwo) {
    size_t diff, lenOne = length(headOne), lenTwo = length(headTwo);
    node_ptr<T> primHead, secHead;

    if(lenOne < lenTwo) {
        primHead = headTwo;
        secHead = headOne;
        diff = lenTwo - lenOne;
    } else {
        primHead = headOne;
        secHead = headTwo;
        diff = lenOne - lenTwo;
    }

    for(size_t it = 0; it != diff; ++it)
        primHead = primHead->next;

    while(primHead) {
        if(primHead == secHead)
            return primHead;
        primHead = primHead->next;
        secHead = secHead->next;
    }
}

/* Given a reference to list and references to two elements in the same list,
 * swap the elements
 */
template <typename T>
void swap(node_ptr<T>& head, const node_ptr<T>& nodeOne, const node_ptr<T>& nodeTwo) {
    if(!(head && nodeOne && nodeTwo))
        return;

    node_ptr<T> tempOne = head, tempTwo = head;

    if(nodeOne == head) {
        while(tempTwo->next != nodeTwo)
            tempTwo = tempTwo->next;

        tempOne = nodeOne->next;
        nodeOne->next = nodeTwo->next;
        nodeTwo->next = tempOne;
        tempTwo->next = nodeOne;
        head = nodeTwo;
    } 
}
