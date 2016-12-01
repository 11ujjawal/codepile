/* Find the union and intersection of two sorted arrays */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getUnion(vector<int>& ivecOne, vector<int>& ivecTwo);
vector<int> getIntersection(vector<int>& ivecOne, vector<int>& ivecTwo);

int main(void) {
    vector<int> ivecOne{1, 2, 3, 5, 6, 7, 9, 10}, ivecTwo{4, 5, 8, 9};

    auto ivecUnion = getUnion(ivecOne, ivecTwo);
    auto ivecIntersect = getIntersection(ivecOne, ivecTwo);

    cout << "Union: ";
    for(vector<int>::iterator ix = ivecUnion.begin(); ix != ivecUnion.end(); ++ix)
        cout << *ix << ' ';

    cout << "\nIntersection: ";
    for(vector<int>::iterator ix = ivecIntersect.begin(); ix != ivecIntersect.end(); ++ix)
        cout << *ix << ' ';
    cout << endl;

    return 0;
}

vector<int> getUnion(vector<int>& ivecOne, vector<int>& ivecTwo) {
    vector<int> ivec;
    vector<int>::iterator iterOne = ivecOne.begin(), iterTwo = ivecTwo.begin();

    while(iterOne != ivecOne.end() && iterTwo != ivecTwo.end()) {
        if(*iterOne < *iterTwo) {
            ivec.push_back(*iterOne);
            iterOne++;
        } else if(*iterTwo < *iterOne) {
            ivec.push_back(*iterTwo);
            iterTwo++;
        } else {
            ivec.push_back(*iterOne);
            iterOne++;
            iterTwo++;
        }
    }

    for(; iterOne != ivecOne.end(); ++iterOne)
        ivec.push_back(*iterOne);

    for(; iterTwo != ivecTwo.end(); ++iterTwo)
        ivec.push_back(*iterTwo);

    return ivec;
}

vector<int> getIntersection(vector<int>& ivecOne, vector<int>& ivecTwo) {
    vector<int> ivec;
    vector<int>::iterator iterOne = ivecOne.begin(), iterTwo = ivecTwo.begin();

    while(iterOne != ivecOne.end() && iterTwo != ivecTwo.end()) {
        if(*iterOne < *iterTwo) {
            iterOne++;
        } else if(*iterTwo < *iterOne) {
            iterTwo++;
        } else {
            ivec.push_back(*iterOne);
            iterOne++;
            iterTwo++;
        }
    }

    return ivec;
}
