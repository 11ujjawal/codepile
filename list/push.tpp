/* Given a reference to the list, insert a new node at the start */
template <typename T>
void push_front(node_ptr<T>& head, const T& key) {
    if(!head) {
        head = make_node(key);
        return;
    }

    node_ptr<T> temp = make_node(key);
    temp->next = head;
    head = temp;
}

/* Given a reference to the list and a value, append the given value */
template <typename T>
void push_back(node_ptr<T>& head, const T& key) {
    if(!head) {
        head = make_node(key);
        return;
    }

    node_ptr<T> counter = head;
    while(counter->next != nullptr)
        counter = counter->next;

    counter->next = make_node(key);
}

/* Given a reference to a node in the list, insert a new node after the given node reference */
template <typename T>
void push_at(node_ptr<T>& node, const T& key) {
    if(!node)
        return;

    node_ptr<T> temp = make_node(key);
    temp->next = node->next;
    node->next = temp;
}

/* Given a reference to a sorted list, insert a new node */
template <typename T>
void push_sorted(node_ptr<T>& head, const T& key) {
    if(!head) {
        head = make_node(key);
        return;
    }

    if(key < head->data) {
        node_ptr<T> temp = make_node(key);
        temp->next = head;
        head = temp;
        return;
    }

    node_ptr<T> currIter, prevIter;
    currIter = prevIter = head;

    while(currIter && currIter->data < key) {
        prevIter = currIter;
        currIter = currIter->next;
    }

    if(currIter && currIter->data >= key) {
        prevIter->next = make_node(key);
        prevIter->next->next = currIter;
    }
}
