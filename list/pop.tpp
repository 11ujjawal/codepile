/* Given a reference to the list, delete the node from the beginning of the list */
template <typename T>
void pop_front(node_ptr<T>& head) {
    if(!head)
        return;

    node_ptr<T> temp = head;
    head = head->next;
}

/* Given a reference to a list, delete the node from the end */
template <typename T>
void pop_back(node_ptr<T>& head) {
    if(!head)
        return;

    if(head->next == nullptr) {
        head = nullptr;
        return;
    }

    node_ptr<T> iter = head;
    while(iter->next->next != nullptr)
        iter = iter->next;

    iter->next = nullptr;
}

/* Given a reference to a node, delete the node after it */
template <typename T>
void pop_at(node_ptr<T>& node) {
    if(!node && !node->next)
        return;

    node->next = node->next->next;
}

/* Given a reference to a node, delete the list */
template <typename T>
void pop_all(node_ptr<T>& head) {
    if(!head)
        return;

    head = nullptr;
}

/* Given a reference to a node, delete the kth element from back */
template <typename T>
void pop_k_back(node_ptr<T>& head, const size_t index) {
    if(!head)
        return;

    node_ptr<T> iterSlow, iterFast;
    iterSlow = iterFast = head;

    size_t counter = 0;
    while(iterFast && counter != index + 1) {
        iterFast = iterFast->next;
        counter++;
    }

    if(!iterFast)
        return;

    while(iterFast) {
        iterFast = iterFast->next;
        iterSlow = iterSlow->next;
    }

    iterSlow->next = iterSlow->next->next;
}

/* Remove duplicates from a sorted list */
template <typename T>
void pop_dups(node_ptr<T>& head) {
    if(!head)
        return;

    node_ptr<T> currNode, prevNode;
    prevNode = head;
    currNode = head->next;

    while(currNode) {
        if(prevNode->data == currNode->data)
            prevNode->next = currNode->next;
        else
            prevNode = prevNode->next;

        currNode = currNode->next;
    }
}
