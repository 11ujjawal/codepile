#include <iostream>
#include <vector>
#include <algorithm>

std::size_t getLongestSeqLen(const std::vector<int>& seqOne, const std::vector<int>& seqTwo);

int main(void) {
    std::vector<int> seqOne{1, 2, 3, 4, 5}, seqTwo{2, 4, 5, 8};

    std::cout << "The longest common sub-sequence in the given sequences is of length -> " << getLongestSeqLen(seqOne, seqTwo) << std::endl;

    return 0;
}

std::size_t getLongestSeqLen(const std::vector<int>& seqOne, const std::vector<int>& seqTwo) {
    std::vector<std::vector<int> > seqCount(seqOne.size() + 1, std::vector<int>(seqTwo.size() + 1, 0));

    std::vector<int>::size_type indexOne, indexTwo;
    for(indexOne = 0; indexOne <= seqOne.size(); ++indexOne)
        for(indexTwo = 0; indexTwo <= seqTwo.size(); ++indexTwo)
            if(!indexOne || !indexTwo)
                seqCount[indexOne][indexTwo] = 0;
            else if(seqOne[indexOne - 1] == seqTwo[indexTwo - 1])
                seqCount[indexOne][indexTwo] = 1 + seqCount[indexOne - 1][indexTwo - 1];
            else
                seqCount[indexOne][indexTwo] = std::max(seqCount[indexOne][indexTwo - 1], seqCount[indexOne - 1][indexTwo]);

    return seqCount[seqOne.size()][seqTwo.size()];
}
