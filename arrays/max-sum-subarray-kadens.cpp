/* Find the maximum sum of an array subarray using kaden's algorithm */

#include <iostream>
#include <vector>

using namespace std;

/* Maximum sum through brute-force method */
int maxSumBruteForce(vector<int> ivec);
int maxSumKadens(vector<int> ivec);
// int maxSumDivAndConq(vector<int> ivec);

int main(void) {
    vector<int> ivec{-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxSumBruteForce(ivec) << endl;
    cout << maxSumKadens(ivec) << endl;

    return 0;
}

/* In the brute force method, we iterate over all possible sub-arrays
 *
 * Time Complexity - O(n^2)
 * Space Complexity - O(1)
 */
int maxSumBruteForce(vector<int> ivec) {
    int ans = 0;

    for(vector<int>::iterator ix = ivec.begin(); ix != prev(ivec.end()); ++ix) {
        int sum = 0;

        for(vector<int>::iterator ixn = next(ix); ixn != ivec.end(); ++ixn) {
            sum += *ixn;

            if(sum > ans)
                ans = sum;
        }
    }

    return ans;
}

/* Kaden's Algorithm
 *
 * Time Complexity - O(n)
 * Space Complexity - O(1)
 */
int maxSumKadens(vector<int> ivec) {
    int max = 0, currMax = 0;

    for(vector<int>::iterator ix = ivec.begin(); ix != ivec.end(); ++ix) {
        currMax += *ix;

        if(currMax < 0)
            currMax = 0;

        if(max < currMax)
            max = currMax;
    }

    return max;
}
