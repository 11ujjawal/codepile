/* Find the smallest and second snallest number in an array */

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findSmall(vector<int> const& ivec);

int main(void) {
    vector<int> ivec{3, 2, 4, 6, 3, 7, 6, 8, 1, 6};
    auto small = findSmall(ivec);
    cout << "Smallest: " << small.first << "\nSecond Smallest: " << small.second << endl;

    return 0;
}

pair<int, int> findSmall(vector<int> const& ivec) {
    int small = INT_MAX, secSmall = INT_MAX;

    for(vector<int>::const_iterator ix = ivec.cbegin(); ix != ivec.cend(); ++ix) {
        if(*ix < small) {
            secSmall = small;
            small = *ix;
        }
        else if(*ix < secSmall && *ix != small)
            secSmall = *ix;
    }

    return make_pair(small, secSmall);
}
