/* Rotate an array */

#include <iostream>
#include <vector>

using namespace std;

/* Rotate using brute force method */
void rotate(vector<int>& ivec, vector<int>::size_type pivot);

/* Rotate using the juggling algorithm */
void rotateJuggle(vector<int>& ivec, vector<int>::size_type pivot);

/* Recursively rotate the elements before and after the pivot */
void rotateRecursive(vector<int>& ivec, vector<int>::size_type pivot);
void reverse(vector<int>::iterator front, vector<int>::iterator back);

int main(void) {
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8};
    rotateRecursive(ivec, 4);

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ++ix)
        cout << *ix << ' ';
    cout << endl;

    return 0;
}

/*
 * Brute - Force approach
 * Time Complexity - O(n * d)
 * Space Complexity - O(1)
 */
void rotate(vector<int>& ivec, vector<int>::size_type pivot) {
    while(pivot > 0) {
        int begElem = ivec.front();
        vector<int>::size_type ix = 1;

        for(; ix != ivec.size(); ++ix)
            ivec[ix - 1] = ivec[ix];

        ivec[ix - 1] = begElem;
        pivot--;
    }
}

void rotateJuggle(vector<int>& ivec, vector<int>::size_type pivot) {
    for(vector<int>::size_type index = 0; index != pivot; ++index) {
        int elem = ivec.at(index);

        vector<int>::size_type ix = index;
        for(; ix < ivec.size() - pivot; ix += pivot)
            swap(ivec.at(ix), ivec.at(ix + pivot));

        swap(ivec.at(ix), elem);
    }
}

/* Recursive rotation approach
 *
 * First rotate the elements before the pivot, then the elements after the pivot
 * and then all the elements
 */
void rotateRecursive(vector<int>& ivec, vector<int>::size_type pivot) {
    vector<int>::iterator pIter = ivec.begin();
    advance(pIter, pivot - 1);

    reverse(ivec.begin(), pIter);
    reverse(next(pIter), prev(ivec.end()));
    reverse(ivec.begin(), prev(ivec.end()));
}

void reverse(vector<int>::iterator front, vector<int>::iterator back) {
    while(front < back)
        swap(*front++, *back--);
}
