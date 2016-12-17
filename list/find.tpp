/* Given a reference to the head of the list and a key, check for the key */
template <typename T>
bool search(const node_ptr<T>& head, const T& key) {
    node_ptr<T> iter = head;

    while(iter != nullptr) {
        if(iter->data == key)
            return true;

        iter = iter->next;
    }

    return false;
}

/* Given a reference to the head of the list and a key, check for the key */
template <typename T>
bool find(const node_ptr<T>& head, const T& key) {
    if(!head)
        return false;

    if(head->data == key)
        return true;

    return find(head->next, key);
}

/* Given a reference to a list, fetch the nth node of a list */
template <typename T>
node_ptr<T> fetch(const node_ptr<T>& head, const size_t index) {
    if(!head)
        return nullptr;

    size_t counter = 1;
    node_ptr<T> iter = head;
    while(iter && counter < index) {
        counter++;
        iter = iter->next;
    }

    if(counter == index && iter)
        return iter;

    return nullptr;
}

/* Given a reference to a list, find the middle node */
template <typename T>
node_ptr<T> fetchMid(const node_ptr<T>& head) {
    if(!head)
        return nullptr;

    if(!head->next)
        return head;

    node_ptr<T> fastIter, slowIter;
    fastIter = slowIter = head;

    while(fastIter->next && fastIter->next->next) {
        fastIter = fastIter->next->next;
        slowIter = slowIter->next;
    }

    return slowIter;
}
