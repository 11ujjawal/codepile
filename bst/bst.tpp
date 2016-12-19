/* Insertion in the tree */
template <typename T>
void bst<T>::insert(const T& key) {
    if(!root) {
        root = make_node(key);
        return;
    }

    btNode<T> *parentNode, *currNode = root.get();

    while(currNode) {
        parentNode = currNode;

        if(key > currNode->data)
            currNode = currNode->right.get();
        else if(key < currNode->data)
            currNode = currNode->left.get();
    }

    if(key < parentNode->data)
        parentNode->left = make_node(key);
    else
        parentNode->right = make_node(key);
}

/* Removal of items in tree */
template <typename T>
void bst<T>::remove(const T& key) {
    if(!root)
        return;


}

/* Search for an item in the tree */
template <typename T>
bool bst<T>::find(const T& key) {
    if(!root)
        return false;

    btNode<T> *node = root.get();

    while(node) {
        if(node->data == key)
            return true;

        if(node->data > key)
            node = node->left.get();
        else
            node = node->right.get();
    }

    return false;
}

/* Get the minimum value from the tree */
template <typename T>
T* bst<T>::min() {
    if(!root)
        return nullptr;

    btNode<T> *node = root.get();
    while(node->left)
        node = node->left.get();

    return &(node->data);
}
