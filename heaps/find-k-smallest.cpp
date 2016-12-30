/* Find the kth smallest element in the array */

#include <iostream>
#include <vector>
#include "heap.hpp"

using namespace std;

int kSmallest(const vector<int>& ivec, const size_t index);
int getkSmallest(vector<int>& ivec, const size_t index);

int main(void) {
    vector<int> ivec{3, 2, 6, 4, 8, 9, 1, 0};
    cout << kSmallest(ivec, 5) << endl;
    cout << getkSmallest(ivec, 5) << endl;

    return 0;
}

/* Get the k-smallest value in a vector using heaps */
int kSmallest(const vector<int>& ivec, const size_t index) {
    /* Initialize a heap object */
    heap<int> H;

    /* Insert the elements */
    for(const auto val : ivec)
        H.insert(val);

    /* Extract elements one less than the required */
    for(size_t ix = 0; ix < index - 1; ++ix)
        H.extractMin();

    /* Fetch the minimum element in the heap */
    return H.getMin();
}

/* Get the k-th smallest element using bubble sort */
int getkSmallest(vector<int>& ivec, const size_t index) {
    for(vector<int>::size_type ix = 0; ix != index; ++ix)
        for(vector<int>::size_type iy = ix + 1; iy != ivec.size(); ++iy)
            if(ivec.at(ix) > ivec.at(iy))
                swap(ivec.at(ix), ivec.at(iy));

    return ivec.at(index - 1);
}
