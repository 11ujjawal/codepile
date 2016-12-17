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
