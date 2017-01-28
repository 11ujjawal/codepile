/* Find the ceil of a sorted array */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getCeil(const vector<int>& ivec, const int key);

int main(void) {
    vector<int> ivec{2, 3, 5, 6, 8, 9, 10, 13, 15, 16, 20};

    cout << "The ceil of 12 is: " << getCeil(ivec, 12) << endl;

    return 0;
}

int getCeil(const vector<int>& ivec, const int key) {
    vector<int>::const_iterator begin = ivec.begin(), end = prev(ivec.end()), mid;

    if(key < *begin)
        return *begin;

    if(key > *end)
        return INT_MAX;

    while(begin < end) {
        mid = begin;
        advance(mid, distance(begin, end) / 2);

        if(key >= *mid && key < *(mid + 1))
            return *(mid + 1);

        if(key > *mid)
            begin = next(mid);
        else
            end = prev(mid);
    }
}
