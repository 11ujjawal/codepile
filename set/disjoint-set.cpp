/* Disjoint Set Data Structure
 *
 * The below DS demonstrates fast UNION and slow FIND
 */

#include <iostream>
#include <vector>
#include <initializer_list>
#include <unordered_map>

using namespace std;

class DisjointSet {
    /* The item-key relation is to be maintained by an unordered map. The key
     * is the item and the value is the element which is the representative of
     * the set the given key is in.
     */
    unordered_map<char, char> data;

public:
    /* Make-Set()
     * The makeSet() takes in the items and places them all in an individual set.
     * To maintain the relation, it assigns both the key and value to the given
     * element. This denotes that the parent of the element is the element itself.
     */
    DisjointSet(initializer_list<char> values) {
        for(char ch : values) {
            data[ch] = ch;
        }
    }

    /* Find()
     * Returns the represntative of the set, the given element is in.
     * To fetch the representative of the set, the method recursively calls the
     * parent of the current element until the parent element is the element
     * itself.
     *
     * Time Complexity - O(n)
     * Space Complexity - O(1)
     */
    char Find(char item) {
        if(data[item] == item)
            return item;
        else
            Find(data[item]);
    }

    /* Union()
     * Unites the two given set into a new set.
     * The representative element of setOne is changes to setTwo.
     *
     * Time Complexity - O(1)
     * Space Complexity - O(1)
     */
    void Union(char setOne, char setTwo) {
        data[setOne] = setTwo;
    }
};

int main(void) {
    DisjointSet ds{'a', 'b', 'c', 'd', 'e'};

    cout << "Set of item 'a': " << ds.Find('a') << endl;

    ds.Union('a', 'b');
    cout << "Set of item 'a': " << ds.Find('a') << endl;

    return 0;
}
