/* Binary minHeap implementation in C++ */

#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <vector>

template <typename T>
using size = typename std::vector<T>::size_type;

template <class T>
class heap {
    std::vector<T> data;
    size<T> parent(size<T> index) { return (index - 1) / 2; }
    size<T> leftChild(size<T> index) { return 2 * index + 1; }
    size<T> rightChild(size<T> index) {return 2 * index + 2; }
    void buildMinHeap();
    void heapifyUp(size<T> index);
    void heapifyDown(size<T> index);

public:
    heap() = default;
    heap(std::initializer_list<T> values);
    T getMin();
    std::vector<T> sort(void);
    void extractMin();
    void insert(T key);
    void remove(size<T> index);
    void decreaseKey(size<T> index, T key);
    void print(void);
};

#include "heap.tpp"

#endif
