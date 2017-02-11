/* Implement quicksort in C++ */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using iter = vector<int>::iterator;

void quicksort(iter begin, iter end);
iter partition(iter begin, iter end);

int main(void) {
    vector<int> ivec{4, 3, 6, 8, 5, 9, 2, 0};
    quicksort(ivec.begin(), prev(ivec.end()));

    for(auto const digit : ivec)
        cout << digit << ' ';
    cout << endl;

    return 0;
}

void quicksort(iter begin, iter end) {
    if(begin > end)
        return;

    iter pivot = partition(begin, end);
    quicksort(begin, prev(pivot));
    quicksort(next(pivot), end);
}

iter partition(iter begin, iter end) {
    iter front = prev(begin), back = begin;

    while(back != end) {
        if(*back < *end)
            swap(*++front, *back);
        back++;
    }

    swap(*++front, *end);
    return front;
}
