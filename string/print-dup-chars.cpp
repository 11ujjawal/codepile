/* Print all the duplicate charactes in a string */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printDupChars(string& text);

int main(void) {
    string text("This is a string");
    printDupChars(text);

    return 0;
}

void printDupChars(string& text) {
    unordered_map<char, int> count;

    for(string::const_iterator ch = text.cbegin(); ch != text.cend(); ++ch)
        count[*ch]++;

    for(unordered_map<char, int>::const_iterator iter = count.cbegin(); iter != count.cend(); ++iter)
        if(iter->second > 1)
            cout << (iter->first) << endl;
}
