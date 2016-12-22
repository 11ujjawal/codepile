/* Fetch the maximum occurring character in the given string */

#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

char getMaxCount(const string& text);

int main(void) {
    string text("This is a string");
    cout << "Maximum occurring character in text '" << text << "' is " << getMaxCount(text) << endl;

    return 0;
}

char getMaxCount(const string& text) {
    unordered_map<char, int> count;

    for(string::const_iterator ch = text.cbegin(); ch != text.cend(); ++ch)
        count[*ch]++;

    char maxChar;
    int max = INT_MIN;

    for(auto const & ix : count)
        if(ix.second > max)
            maxChar = ix.first;

    return maxChar;
}
