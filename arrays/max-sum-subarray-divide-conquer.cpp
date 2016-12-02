/* Max sum subarray using divide and conquer */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
using iter = vector<int>::iterator;

int getMaxSum(iter begin, iter end);
int getMaxCross(iter begin, iter mid, iter end);

int main(void) {
    vector<int> ivec{1, 4, -2, -4, -9, 2, 6, -4, 6, -1};
    cout << getMaxSum(ivec.begin(), prev(ivec.end())) << endl;

    return 0;
}

int getMaxSum(iter begin, iter end) {
    if(begin == end)
        return *begin;

    iter mid = begin;
    advance(mid, distance(begin, end) / 2);

    auto lMax = getMaxSum(begin, mid);
    auto rMax = getMaxSum(next(mid), end);
    auto cMax = getMaxCross(begin, mid, end);

    return max(cMax, max(lMax, rMax));
}

int getMaxCross(iter begin, iter mid, iter end) {
    int lMax = INT_MIN, rMax = INT_MIN;
    int lSum = 0, rSum = 0;

    for(iter li = mid; li >= begin; --li) {
        lSum += *li;
        if(lMax < lSum)
            lMax = lSum;
    }

    for(iter ri = next(mid); ri <= end; ++ri) {
        rSum += *ri;
        if(rMax < rSum)
            rMax = rSum;
    }

    return lMax + rMax;
}
