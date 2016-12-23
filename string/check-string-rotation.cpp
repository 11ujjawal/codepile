/* Check whether strings are rotation of each other */

#include <iostream>
#include <string>

using namespace std;

/* Check if strTwo is rotation of strOne */
bool checkRotation(const string& strOne, const string& strTwo);

int main(void) {
    string strOne("ABACD"), strTwo("CDABA");
    cout << checkRotation(strOne, strTwo) << endl;

    return 0;
}

/* Check whether a string contains its rotation.
 *
 * Example -> str: ABACD
 * Rotation of str -> CDABA
 *
 * Concatenation of string with itself yields ABACDABACD
 * Check if the second string is a subset of this string.
 */
bool checkRotation(const string& strOne, const string& strTwo) {
    string str = strOne + strOne;

    if(str.find(strTwo) != string::npos)
        return true;

    return false;
}
