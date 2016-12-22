/* Remove character present in second string from the first string */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string substract(const string& textOne, const string& textTwo);

int main(void) {
    string textOne("abcdef"), textTwo("acegh");
    cout << "Characters in '" << textOne << "' not in '" << textTwo << "' are : " << substract(textOne, textTwo) << endl;

    return 0;
}

string substract(const string& textOne, const string& textTwo) {
    unordered_map<char, int> count;
    string str;

    for(string::const_iterator ch = textTwo.cbegin(); ch != textTwo.cend(); ++ch)
        count[*ch]++;

    for(string::const_iterator ch = textOne.cbegin(); ch != textOne.cend(); ++ch)
        if(!count[*ch])
            str += *ch;

    return str;
}
