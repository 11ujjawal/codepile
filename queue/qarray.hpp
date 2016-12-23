/* Queue implementation using arrays */

#ifndef _QARRAY_HPP
#define _QARRAY_HPP

#include <memory>
#include <stdexcept>

/* Queue Data Type */
template <class T, size_t length>
class qArray {
    /* element index counter */
    size_t index;

    /* data is a pointer to the array */
    std::unique_ptr<T[]> data;

public:
    qArray();

    /* Inser element in queue */
    void push(const T& key);

    /* Remove elements from queue */
    void pop();

    /* Peek the first element */
    T& front();

    /* Peek the last element */
    T& back();

    /* Check if the queue is empty */
    bool empty();

    /* Check if the queue if full */
    bool full();

    /* Get the total number of elements */
    size_t size();

    /* Subscript operator overloading */
    T& operator[](size_t key);
};

/* Array constructor */
template <class T, size_t length>
qArray<T, length>::qArray() : index(0) {
    data = std::make_unique<T[]>(length);
}

template <class T, size_t length>
void qArray<T, length>::push(const T& key) {
    if(full())
        throw std::out_of_range("Cannot insert in a full queue");

    data[index++] = key;
}

template <class T, size_t length>
void qArray<T, length>::pop() {
    if(empty())
        throw std::out_of_range("Cannot remove a value from an empty queue");

    /* Removing an elements initiates copy of the rest to reuse memory */
    for(size_t ix = 1; ix != length; ++ix)
        data[ix - 1] = data[ix];
    index--;
}

template <class T, size_t length>
T& qArray<T, length>::front() {
    if(empty())
        throw std::out_of_range("Cannot fetch a value from an empty queue");

    return data[0];
}

template <class T, size_t length>
T& qArray<T, length>::back() {
    if(empty())
        throw std::out_of_range("Cannot fetch a value from an empty queue");

    return data[index - 1];
}

template <class T, size_t length>
T& qArray<T, length>::operator[](size_t key) {
    if(key < 0)
        throw std::out_of_range("Index cannot be negative");

    if(key > index)
        throw std::out_of_range("Index is greater than queue element list");

    return data[key];
}

template <class T, size_t length>
bool qArray<T, length>::empty() {
    return index == 0;
}

template <class T, size_t length>
bool qArray<T, length>::full() {
    return index == length;
}

template <class T, size_t length>
size_t qArray<T, length>::size() {
    return index;
}
#endif
