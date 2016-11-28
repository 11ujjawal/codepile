/* Reverse a vector of numbers */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reverse(vector<int> &ivec);

int main(void) {
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8};
    reverse(ivec);

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ++ix)
        cout << *ix << ' ';
    cout << endl;

    return 0;
}

void reverse(vector<int> &ivec) {
    for(vector<int>::iterator beg = ivec.begin(), end = prev(ivec.end()); beg < end; ++beg, --end)
        swap(*beg, *end);
}
