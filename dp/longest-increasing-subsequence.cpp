/* Get the longest increasing subsequence of a vector of integers */
#include <iostream>
#include <vector>
#include <algorithm>

int getLongestIncSeqLen(const std::vector<int>& ivec);

int main(void) {
    std::vector<int> ivec{10, 22, 9, 33, 21, 50, 41, 60};

    std::cout << getLongestIncSeqLen(ivec) << std::endl;

    return 0;
}

/*
 * Longest Increasing SubSequence using DP
 * Time Complexity - O(n^2)
 */
int getLongestIncSeqLen(const std::vector<int>& ivec) {
    std::vector<int> seqCount(ivec.size(), 1);
    std::vector<int>::size_type pIndex = 0, sIndex;

    for(; pIndex != ivec.size(); ++pIndex)
        for(sIndex = 0; sIndex != pIndex; ++sIndex)
            if(ivec.at(pIndex) > ivec.at(sIndex) && seqCount.at(pIndex) < seqCount.at(sIndex) + 1)
                seqCount.at(pIndex) = seqCount.at(sIndex) + 1;

    return *std::max_element(seqCount.begin(), seqCount.end());
}
