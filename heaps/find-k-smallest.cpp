/* Find the kth smallest element in the array */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kSmallest(vector<int>& ivec, int index);

int main(void) {
    vector<int> ivec{3, 2, 6, 4, 8, 9, 1, 0};
    cout << kSmallest(ivec, 4) << endl;

    return 0;
}

int kSmallest(vector<int>& data, int index) {
    make_heap(data.begin(), data.end());
    sort_heap(data.begin(), data.end());

    return data[index - 1];
}
