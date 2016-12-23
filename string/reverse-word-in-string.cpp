/* Reverse words in a string.
 * Example -
 * String -> 'this is a string'
 * output -> 'string a is this'
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

string getWordReverse(const string& text);

int main(void) {
    string textOne("this is a string"), textTwo("reverse   this  new string");
    cout << getWordReverse(textOne) << endl;
    cout << getWordReverse(textTwo) << endl;

    return 0;
}

string getWordReverse(const string& text) {
    string str = text;

    string::iterator start, end, ch;
    start = ch = str.begin();

    for(; ch != str.end(); ++ch) {
        if(isspace(*ch)) {
            end = prev(ch);
            while(start < end)
                swap(*start++, *end--);

            while(isspace(*ch))
                ch++;

            start = ch;
        }
    }

    end = prev(ch);
    while(start < end)
        swap(*start++, *end--);

    for(start = str.begin(), end = prev(str.end()); start < end; ++start, --end)
        swap(*start, *end);

    return str;
}
