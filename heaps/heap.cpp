/* A minHeap implementation in C++ */

#include <iostream>
#include <algorithm>
#include <limits>
#include "heap.hpp"

using namespace std;

int main(void) {
    /* Use initializer list to initialize a minHeap object */
    heap<int> minHeap{1, 3, 5, 2, 6, 8};
    minHeap.print();

    /* Invoke insert method to add more value */
    minHeap.insert(4);
    minHeap.print();

    return 0;
}

/* Constructor method to accept initializer list */
template <class T>
heap<T>::heap(initializer_list<T> values) {
    for(typename initializer_list<T>::iterator ix = values.begin(); ix != values.end(); ix++)
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
        swap(data[index], data[min]);
        heapifyDown(min);
    }
}

/* Fetch the minimum value, which is the first element in the array */
template <class T>
T heap<T>::getMin() {
    if(!data.size())
        return numeric_limits<T>::lowest();

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
        swap(data[pat], data[index]);
        heapifyUp(pat);
    }
}

/* Sort the elements in the heap, this method has O(n) space complexity */
template <class T>
vector<T> heap<T>::sort() {
    vector<T> ivec;

    for(size<T> ix = data.size() - 1; ix < data.size(); --ix) {
        swap(data[0], data[ix]);
        ivec.push_back(data.back());
        data.pop_back();
        heapifyDown(0);
    }

    return ivec;
}

/* Display the values in the heap */
template <class T>
void heap<T>::print() {
    for(size<T> ix = 0; ix != data.size(); ++ix)
        cout << data.at(ix) << ' ';
    cout << endl;
}
