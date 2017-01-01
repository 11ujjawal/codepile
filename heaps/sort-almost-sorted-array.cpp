/* Sort an almost sorted array */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/* The function takes in a vector of integers and a key. The key denots the
 * distance of the current number from its correctly sorted position i.e. no
 * number is key distance from its final sorted position.
 */
void printSort(const vector<int>& ivec, const size_t key);

int main(void) {
    const size_t key = 3;
    vector<int> ivec{3, -1, 2, 6, 4, 5, 8};

    printSort(ivec, key);

    return 0;
}

/* The idea is after reading key numbers, the minimum number should be at the
 * starting of the interval since, the sequence contains numbers atmost key
 * distance from its final position.
 */
void printSort(const vector<int>& ivec, const size_t key) {
    /* Min heap data structure is employed. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
    vector<int>::size_type ix = 0;

    /* (key + 1) elements are added to the heap. The minimum element can be
     * extracted efficiently and the next number added
     */
    for(; ix != key; ++ix)
        minHeap.push(ivec.at(ix));

    for(; ix != ivec.size(); ++ix) {
        minHeap.push(ivec.at(ix));
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }

    /* Extract the remaining elements which will yield the minimum element each
     * time
     */
    while(!minHeap.empty()) {
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }

    cout << endl;
}
