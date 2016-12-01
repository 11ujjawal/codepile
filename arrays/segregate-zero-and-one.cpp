/* Segregate 0 and 1 in an array */

#include <iostream>
#include <vector>

using namespace std;

void segregate(vector<int>& ivec);

int main(void) {
    vector<int> ivec{0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1};
    segregate(ivec);

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ix++)
        cout << *ix << ' ';
    cout << endl;

    return 0;
}

void segregate(vector<int>& ivec) {
    vector<int>::iterator start = ivec.begin(), end = prev(ivec.end());

    while(start <= end) {
        if(*start == 1) {
            swap(*start, *end);
            end--;
        } else {
            start++;
        }
    }
}
