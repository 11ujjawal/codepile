/* Disjoint Set Data Structure */

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

    /* The item-key relation stores the rank of the element. One element
     * pointing to the other to denote its parent forms a tree. This tree
     * can drag the time when one wants invokes the find(), because of numerous
     * recursive calls. The rank specifies the height of the tree. We append to
     * tree with low height and hence, accelerate the find().
     */
    unordered_map<char, int> rank;

public:
    /* Make-Set()
     * The makeSet() takes in the items and places them all in an individual set.
     * To maintain the relation, it assigns both the key and value to the given
     * element. This denotes that the parent of the element is the element itself.
     */
    DisjointSet(initializer_list<char> values) {
        for(char ch : values) {
            data[ch] = ch;
            rank[ch] = 0;
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
        if(data[item] != item)
            data[item] = Find(data[item]);

        return data[item];
    }

    /* Union()
     * Unites the two given set into a new set.
     * The representative element of setOne is changes to setTwo.
     *
     * Time Complexity - O(1)
     * Space Complexity - O(1)
     */
    void Union(char setOne, char setTwo) {
        if(rank[setOne] > rank[setTwo])
            data[setTwo] = setOne;
        else if(rank[setTwo] > rank[setOne])
            data[setOne] = setTwo;
        else {
            data[setOne] = setTwo;
            rank[setTwo]++;
        }
    }
};

int main(void) {
    DisjointSet ds{'a', 'b', 'c', 'd', 'e'};

    cout << "Set of item 'a': " << ds.Find('a') << endl;

    ds.Union('a', 'b');
    cout << "Set of item 'a': " << ds.Find('a') << endl;

    ds.Union('c', 'b');
    cout << "Set of item 'c': " << ds.Find('c') << endl;

    ds.Union('d', 'b');
    cout << "Set of item 'd': " << ds.Find('d') << endl;

    return 0;
}
