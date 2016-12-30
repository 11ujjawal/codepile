/* A minHeap implementation in C++ */

#include <iostream>
#include <algorithm>
#include "heap.hpp"

/* Constructor method to accept initializer list */
template <class T>
heap<T>::heap(std::initializer_list<T> values) {
    for(typename std::initializer_list<T>::iterator ix = values.begin(); ix != values.end(); ix++)
        data.push_back(*ix);

    buildMinHeap();
}

/* Method to build a min heap from the current values in the vector */
template <class T>
void heap<T>::buildMinHeap() {
    for(size<T> index = data.size() / 2; index < data.size(); --index)
        heapifyDown(index);
}

/* Heapify the elements below the given index */
template <class T>
void heap<T>::heapifyDown(size<T> index) {
    size<T> min = index;
    size<T> lchild = leftChild(index);
    size<T> rchild = rightChild(index);

    if(lchild < data.size() && data[min] > data[lchild])
        min = lchild;
    if(rchild < data.size() && data[min] > data[rchild])
        min = rchild;

    if(index != min) {
        std::swap(data[index], data[min]);
        heapifyDown(min);
    }
}

/* Fetch the minimum value, which is the first element in the array */
template <class T>
T heap<T>::getMin() {
    if(!data.size())
        return std::numeric_limits<T>::lowest();

    return data.front();
}

/* Remove the minimum element from the array and heapify the remaining element */
template <class T>
void heap<T>::extractMin() {
    if(!data.size())
        return;

    data[0] = data[data.size() - 1];
    data.pop_back();
    heapifyDown(0);
}

/* Insert a new element in the heap */
template <class T>
void heap<T>::insert(T key) {
    data.push_back(key);
    heapifyUp(data.size() - 1);
}

/* Heapify the elements which are the parent of the given index */
template <typename T>
void heap<T>::heapifyUp(size<T> index) {
    if(index >= data.size())
        return;

    size<T> pat = parent(index);
    if(pat >= data.size())
        return;

    if(data[pat] > data[index]) {
        std::swap(data[pat], data[index]);
        heapifyUp(pat);
    }
}

/* Sort the elements in the heap, this method has O(n) space complexity */
template <class T>
std::vector<T> heap<T>::sort() {
    std::vector<T> ivec;

    for(size<T> ix = data.size() - 1; ix < data.size(); --ix) {
        std::swap(data[0], data[ix]);
        ivec.push_back(data.back());
        data.pop_back();
        heapifyDown(0);
    }

    return ivec;
}

/* Delete element at the given index */
template <class T>
void heap<T>::remove(size<T> index) {
    if(data.empty() || index >= data.size())
        return;

    data.at(index) = INT_MIN;
    heapifyUp(index);
    extractMin();
}

/* Decreased the value of key at given index */
template <typename T>
void heap<T>::decreaseKey(size<T> index, T key) {
    if(index >= data.size())
        return;

    data.at(index) = key;
    heapifyUp(index);
}


/* Display the values in the heap */
template <class T>
void heap<T>::print() {
    for(size<T> ix = 0; ix != data.size(); ++ix)
        std::cout << data.at(ix) << ' ';
    std::cout << std::endl;
}
