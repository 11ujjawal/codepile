/* Find the minimum and maximum of array */

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getMinMax(vector<int>::iterator, vector<int>::iterator);
pair<int, int> getMinMaxPair(pair<int, int> pairOne, pair<int, int> pairTwo);

int main(void) {
    vector<int> ivec{5, 2, 4, 9, 7, 1, 6, 8};
    pair<int, int> result = getMinMax(ivec.begin(), prev(ivec.end()));
    cout << "Min: " << result.first << " Max: " << result.second << endl;

    return 0;
}

pair<int, int> getMinMax(vector<int>::iterator start, vector<int>::iterator end) {
    int dist = distance(start, end);

    if(dist == 0)
        return make_pair(*start, *start);
    else if(dist == 1) {
        if(*start < *end)
            return make_pair(*start, *end);
        else
            return make_pair(*end, *start);
    }
    else {
        auto lvec = getMinMax(start, end - dist / 2);
        auto rvec = getMinMax(start + dist / 2, end);
        return getMinMaxPair(lvec, rvec);
    }
}

pair<int, int> getMinMaxPair(pair<int, int> pairOne, pair<int, int> pairTwo) {
    return make_pair((pairOne.first < pairTwo.first) ? pairOne.first : pairTwo.first,
                (pairOne.second > pairTwo.second) ? pairOne.second : pairTwo.second);
}
