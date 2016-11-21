/* A quick tour of the stack data structure in the C++ STL
 *
 * Containers are data types from STL that contain data. An adapter takes an
 * existing container type and makes it act like a different abstract type
 * (most likely by providing an interface). Stack is a container adapter and by
 * default uses deque as base container. Stack does not support iterators.
 *
 * Operations -
 * 1. empty
 * 2. size
 * 3. back
 * 4. push_back
 * 5. pop_back
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(void) {
    deque<int> ideq(3, 100);
    vector<string> ivec;

    /* Declare stack with default deque base container */
    stack<int> sint;
    stack<string> sstr;

    /* Explicitely declare stack with deque base container and initialize it with the deque container */
    stack<int, deque<int> > sdeq(ideq);

    /* Declare stack with vector base container */
    stack<string, vector<string> > svec;

    /* Declare stack with list base container */
    stack<int, list<int> > slist;

    cout << "Stacks after declaration" << endl;
    cout << "Size of default stack: " << sint.size() << endl;
    cout << "Size of deque initialized stack: " << sdeq.size() << endl;
    cout << "Size of stack declard with vector as base container: " << svec.size() << endl;
    cout << "Size of stack declard with list as base container: " << slist.size() << endl;

    /* Store first 10 integers in sint and find their sum */
    int sum = 0;
    for(int i = 1; i != 10; i++)
        sint.push(i);

    while(!sint.empty()) {
        sum += sint.top();
        sint.pop();
    }

    cout << "Sum of first 10 integers is: " << sum << endl;

    /* emplace is like push(). The difference is that emplace creates another instance of the container class that's already appended to container. The arguments to emplace ar forwarded as arguments to the constructor */
    svec.emplace("First sentence");
    svec.emplace("Second sentence");

    while(!svec.empty()) {
        cout << svec.top() << endl;
        svec.pop();
    }

    return 0;
}
