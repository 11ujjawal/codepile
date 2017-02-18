#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::size_t getEditCharCount(const std::string& strOne, const std::string& strTwo);

int main(void) {
    std::string strOne("abcdefgh"), strTwo("acdfijk");

    std::cout << "Edits needed to transform '" << strOne << "' to '" << strTwo << "': " << getEditCharCount(strOne, strTwo) << std::endl;
    return 0;
}

std::size_t getEditCharCount(const std::string& strOne, const std::string& strTwo) {
    std::vector<std::vector<std::size_t> > editDistCount(strOne.size() + 1, std::vector<std::size_t>(strTwo.size() + 1, 0));

    for(std::size_t pIndex = 0; pIndex <= strOne.size(); ++pIndex)
        for(std::size_t sIndex = 0; sIndex <= strTwo.size(); ++sIndex)
            if(!pIndex)
                editDistCount[pIndex][sIndex] = sIndex;
            else if(!sIndex)
                editDistCount[pIndex][sIndex] = pIndex;
            else if(strOne.at(pIndex - 1) == strTwo.at(sIndex - 1))
                editDistCount[pIndex][sIndex] = editDistCount[pIndex - 1][sIndex - 1];
            else
                editDistCount[pIndex][sIndex] = 1 + std::min(std::min(editDistCount[pIndex - 1][sIndex], editDistCount[pIndex][sIndex - 1]), editDistCount[pIndex - 1][sIndex - 1]);

    return editDistCount[strOne.size()][strTwo.size()];
}
