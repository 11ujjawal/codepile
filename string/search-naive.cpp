/* A naive string search algorithm with zero indexed array.
 * The C++ STL provides find() for searching pattern.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Search the text for the pattern */
vector<size_t> search(const string& text, const string& pattern);

/* Print the indexes returned */
void print(const std::vector<size_t>& pText);

int main(void) {
    string textOne("This is a string"), textTwo("This is another string");
    string pattern("another");

    print(search(textOne, pattern));
    print(search(textTwo, pattern));

    return 0;
}

vector<size_t> search(const string& text, const string& pattern) {
    vector<size_t> pText;

    for(std::string::size_type textIndex = 0; textIndex != text.size() - pattern.size() + 1; ++textIndex) {
        std::string::size_type pIndex = 0, tIndex = textIndex;

        for(; pIndex != pattern.size(); ++pIndex, ++tIndex)
            if(text.at(tIndex) != pattern.at(pIndex))
                break;

        if(pIndex == pattern.size())
            pText.push_back(textIndex);
    }

    return pText;
}

/* Print the indexes of the pattern found in text */
void print(const std::vector<size_t>& pText) {
    if(pText.empty())
        cout << "No match found" << endl;

    for(auto const & pIndex : pText)
        cout << pIndex << endl;

    cout << endl;
}
