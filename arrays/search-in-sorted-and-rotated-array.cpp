#include <iostream>
#include <vector>

using namespace std;

bool findElem(vector<int> const& ivec, int key);

int main(void) {
    vector<int> ivec{5, 6, 7, 8, 1, 2, 3, 4};
    cout << findElem(ivec, 4) << endl;

    return 0;
}

bool findElem(vector<int> const& ivec, int key) {
    vector<int>::const_iterator begin = ivec.begin(), end = prev(ivec.end()), mid;

    while(begin <= end) {
        mid = begin;
        advance(mid, distance(begin, end) / 2);

        if(*mid == key)
            return true;

        if(*mid <= *end) {
            if(key > *mid && key <= *end)
                begin = next(mid);
            else
                end = prev(mid);
        } else {
            if(key >= *begin && key < *mid)
                end = prev(mid);
            else
                begin = next(mid);
        }
    }

    return false;
}
