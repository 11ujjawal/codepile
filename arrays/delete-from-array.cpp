/* Delete a specific number from array */

#include <iostream>
#include <vector>

using namespace std;

void delElem(vector<int> &ivec, int key);

int main(void) {
    vector<int> ivec{1, 3, 2, 5, 4, 6, 2, 3, 2, 2, 4, 7, 8};
    delElem(ivec, 2);

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ix++)
        cout << *ix << ' ';
    cout << endl;

    return 0;
}

void delElem(vector<int> &ivec, int key) {
    vector<int>::iterator i = ivec.begin(), j = ivec.begin();

    while(i != ivec.end()) {
        if(*i == key)
            i++;
        else {
            *j = *i;
            i++;
            j++;
        }
    }

    ivec.erase(j, i);
}
