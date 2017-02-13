#include <iostream>
#include <vector>

std::pair<std::size_t, std::size_t> getSubArrayIndex(const std::vector<int>& ivec);

int main(void) {
    std::vector<int> ivec{10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    auto index = getSubArrayIndex(ivec);

    std::cout << "Left Index: " << index.first << " Right Index: " << index.second << std::endl;

    return 0;
}

std::pair<std::size_t, std::size_t> getSubArrayIndex(const std::vector<int>& ivec) {
    std::vector<int>::size_type begin = 0, end = ivec.size() - 1;

    for(; begin != ivec.size() - 1; ++begin)
        if(ivec.at(begin) > ivec.at(begin + 1))
            break;

    for(; end != 0; --end)
        if(ivec.at(end) < ivec.at(end - 1))
            break;

    std::vector<int>::size_type min = begin, max = begin, index = begin;
    for(; index <= end; ++index) {
        if(ivec.at(min) > ivec.at(index))
            min = index;
        if(ivec.at(max) < ivec.at(index))
            max = index;
    }

    for(; begin < ivec.size(); --begin)
        if(ivec.at(begin) > ivec.at(min))
            min = begin;

    for(; end != ivec.size(); ++end)
        if(ivec.at(end) < ivec.at(max))
            max = end;

    return std::make_pair(min, max);
}
