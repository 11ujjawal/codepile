/* Impelementation of the classic Selection Sort algorithm using both index ops
 * and C++ iterators
 */

#include <iostream>
#include <vector>
#include <algorithm>

void sortIndex(std::vector<int>& ivec);
void sortIter(std::vector<int>& ivec);
void print(const std::vector<int>& ivec);

int main(void) {
    std::vector<int> ivecOne{3, 2, 6, 5, 8, 9, 6, 0}, ivecTwo{4, 1, 5, 8, 3, 6, 9, 8, 0};

    std::cout << "Vector One after Sorting: ";
    sortIndex(ivecOne);
    print(ivecOne);

    std::cout << "Vector Two after Sorting: ";
    sortIter(ivecTwo);
    print(ivecTwo);

    return 0;
}

void sortIndex(std::vector<int>& ivec) {
    for(std::vector<int>::size_type pIndex = 0; pIndex != ivec.size(); ++pIndex) {
        std::vector<int>::size_type sIndex {pIndex};

        while (sIndex > 0 && ivec.at(sIndex) < ivec.at(sIndex - 1)) {
            std::swap(ivec.at(sIndex), ivec.at(sIndex - 1));
            --sIndex;
        }
    }
}

void sortIter(std::vector<int>& ivec) {
    for(std::vector<int>::iterator pIter = ivec.begin(); pIter != ivec.end(); ++pIter) {
        std::vector<int>::iterator sIter {pIter};

        while (*sIter < *prev(sIter)) {
            iter_swap(sIter, prev(sIter));
            --sIter;
        }
    }
}

void print(const std::vector<int>& ivec) {
    for(auto const elem : ivec)
        std::cout << elem << ' ';

    std::cout << std::endl;
}
