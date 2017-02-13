#include <iostream>
#include <memory>

struct Node;

using node_ptr = std::shared_ptr<Node>;

struct Node {
    int data;
    node_ptr next;

    Node(int value) : data(value), next(nullptr) {}
};

void sort(node_ptr& node);
node_ptr merge(node_ptr& nodeOne, node_ptr& nodeTwo);
node_ptr getMidNode(node_ptr& node);

int main(void) {
    node_ptr list = std::make_shared<Node>(10);
    list->next = std::make_shared<Node>(20);
    list->next->next = std::make_shared<Node>(15);
    list->next->next->next = std::make_shared<Node>(18);
    sort(list);

    while(list) {
        std::cout << list->data << std::endl;
        list = list->next;
    }

    return 0;
}

void sort(node_ptr& node) {
    if(!node || !node->next)
        return;

    node_ptr midNode = getMidNode(node);
    sort(node);
    sort(midNode);
    node = merge(node, midNode);
}

node_ptr merge(node_ptr& nodeOne, node_ptr& nodeTwo) {
    if(!nodeOne)
        return nodeTwo;
    else if(!nodeTwo)
        return nodeOne;

    node_ptr result = nullptr;
    if(nodeOne->data < nodeTwo->data) {
        result = nodeOne;
        result->next = merge(nodeOne->next, nodeTwo);
    } else {
        result = nodeTwo;
        result->next = merge(nodeOne, nodeTwo->next);
    }

    return result;
}

node_ptr getMidNode(node_ptr& node) {
    node_ptr fastPtr = node, slowPtr = node, prevPtr;

    while(fastPtr && fastPtr->next) {
        fastPtr = fastPtr->next->next;
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
    }

    prevPtr->next = nullptr;

    return slowPtr;
}
