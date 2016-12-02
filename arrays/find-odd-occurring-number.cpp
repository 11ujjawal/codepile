/* One of the elements in the array occurs odd number of times, find it */

#include <iostream>
#include <vector>

using namespace std;

int getOddCountElem(vector<int>& ivec);

int main(void) {
    vector<int> ivec{1, 2, 1, 2, 3, 4, 4, 5, 5};
    cout << "Element occurring odd number of times: " << getOddCountElem(ivec) << endl;

    return 0;
}

int getOddCountElem(vector<int>& ivec) {
    int num = ivec.front();

    for(vector<int>::iterator ix = next(ivec.begin()); ix != ivec.end(); ix++)
        num ^= *ix;

    return num;
}
