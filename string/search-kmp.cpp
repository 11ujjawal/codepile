/* Implementation of the classic Knuth-Morris-Pratt Algorithm
 *
 * Let m -> Length of text
 * Let n -> Length of pattern
 * Time Complexity - O(n + m)
 */

#include <iostream>
#include <vector>
#include <string>

/* Fetch all the indexes where the pattern matches the text */
std::vector<std::size_t> getPatternMatch(const std::string& text, const std::string& pattern);
std::vector<std::size_t> getPrefixSuffixVec(const std::string& pattern);

int main(void) {
    std::string pattern("abcab"), text("abxabcabcaby");

    auto patternIndex = getPatternMatch(text, pattern);
    for(const auto index : patternIndex)
        std::cout << index << std::endl;

    return 0;
}

std::vector<std::size_t> getPatternMatch(const std::string& text, const std::string& pattern) {
    std::vector<std::size_t> patternIndex;

    auto psMatch = getPrefixSuffixVec(pattern);

    std::string::size_type pIndex = 0, tIndex = 0;

    while(tIndex != text.size()) {

        if(pattern.at(pIndex) == text.at(tIndex)) {
            ++pIndex;
            ++tIndex;

            if(pIndex == pattern.size()) {
                patternIndex.push_back(tIndex - pIndex);
                pIndex = psMatch.at(pIndex - 1);
            }

        } else if(pIndex) {
            pIndex = psMatch.at(pIndex - 1);
        } else {
            ++tIndex;
        }
    }

    return patternIndex;
}

std::vector<std::size_t> getPrefixSuffixVec(const std::string& pattern) {
    std::vector<std::size_t> psMatch(pattern.size());
    std::vector<std::size_t>::size_type psIndex = 0;
    std::string::size_type pIndex = 1;

    while(pIndex != pattern.size()) {
        if(pattern.at(pIndex) == pattern.at(psIndex)) {
            psMatch[pIndex++] = ++psIndex;
        } else {
            if(psIndex)
                psIndex = psMatch[psIndex - 1];
            else
                psMatch[pIndex++] = 0;
        }
    }

    return psMatch;
}
