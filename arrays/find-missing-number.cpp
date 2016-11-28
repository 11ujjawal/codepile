/* Find missing number in the array */

#include <iostream>
#include <vector>

using namespace std;

int findMissingBySum(vector<int> ivec);
int findMissingByXOR(vector<int> ivec);

int main(void) {
    vector<int> ivec{1, 2, 5, 3, 4, 7, 8};
    cout << findMissingBySum(ivec) << endl;
    cout << findMissingByXOR(ivec) << endl;

    return 0;
}

/*
 * Time Complexity - O(n)
 * Space Complexity - O(1)
 */
int findMissingBySum(vector<int> ivec) {
    int sum = (ivec.size() + 1) * (ivec.size() + 2) / 2;
    int vsum = 0;

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ++ix)
        vsum += *ix;

    return sum - vsum;
}

int findMissingByXOR(vector<int> ivec) {
    int numxor = 1,
        vecxor = ivec.front();

    for(int i = 2; i <= ivec.size() + 1; i++)
        numxor ^= i;

    for(vector<int>::iterator ix = next(ivec.begin()); ix != ivec.end(); ++ix)
        vecxor ^= *ix;

    return (numxor ^ vecxor);
}
