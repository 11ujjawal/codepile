/* Given a vector of integers, find the majority element (element occurring
 * at least half positions)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

void printMajorElem(vector<int> ivec);
int findMajorElem(vector<int> ivec);
bool isMajorElem(vector<int> ivec, int elem);

int main(void) {
    vector<int> ivec{1, 2, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2};
    printMajorElem(ivec);

    return 0;
}

void printMajorElem(vector<int> ivec) {
    int majorElem = findMajorElem(ivec);

    if(isMajorElem(ivec, majorElem))
        cout << majorElem << endl;
    else
        cout << "NONE" << endl;
}

int findMajorElem(vector<int> ivec) {
    vector<int>::iterator ix, index = ivec.begin();
    int count = 1;

    for(ix = ivec.begin(); ix != ivec.end(); ++ix) {
        if(*ix == *index)
            count++;
        else
            count--;

        if(count == 0) {
            index = ix;
            count++;
        }
    }

    return *index;
}

bool isMajorElem(vector<int> ivec, int elem) {
    int count = 0;

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ++ix)
        if(*ix == elem)
            count++;

    if(count > ivec.size() / 2)
        return true;
    else
        return false;
}
