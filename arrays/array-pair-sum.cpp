/* Given an array and a sum, check for pair in array with sum x
 *
 * Let an array be [1, 4, 45, 6, 10, -8] and the sum of pair we are looking
 * for be 16. So, 6 + 10 adds to 16 and hence, such a pair is present.
 *
 * Time complexity - The sort function internally uses quicksort which has
 * worst-case time complexity of O(n^2), but average complexity of O(nlogn).
 *
 * Space complexity - O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool hasPair(vector<int> ivec, int key);

int main(void) {
    int key = 16;
    int nums[] = {1, 4, 45, 6, 10, -8};
    vector<int> ivec(nums, nums + 6);

    cout << "Does a pair exists? " << hasPair(ivec, key) << endl;

    return 0;
}

bool hasPair(vector<int> ivec, int key) {
    sort(ivec.begin(), ivec.end());

    int front = 0, back = ivec.size() - 1;
    while(front < back) {
        int sum = ivec[front] + ivec[back];

        if(sum == key)
            return true;
        else if(sum < key)
            front++;
        else
            back--;
    }

    return false;
}
