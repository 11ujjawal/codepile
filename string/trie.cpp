#include <iostream>
#include <string>
#include "trie.hpp"

using std::string;

int main(void) {
    /* The constructor takes in an initializer list of string pattern as argument */
    trie tree({string("answer"), string("any"), string("by"), string("bye"), string("their")});

    /* insert() can be used to add new patterns */
    tree.insert(string("the"));
    tree.insert(string("there"));

    /* Invoke the match() to verify the existance of a pattern */
    std::cout << "After insertion of patterns in trie" << std::endl;
    std::cout << "the -> " << tree.match(string("the")) << std::endl;
    std::cout << "these -> " << tree.match(string("these")) << std::endl;
    std::cout << "their -> " << tree.match(string("their")) << std::endl;
    std::cout << "thaw -> " << tree.match(string("thaw")) << std::endl;
    std::cout << "by -> " << tree.match(string("by")) << std::endl;

    /* remove() is invoked to return patterns stored in trie */
    tree.remove(string("their"));
    tree.remove(string("by"));

    std::cout << "\nAfter removal of patterns in trie" << std::endl;
    std::cout << "their -> " << tree.match(string("their")) << std::endl;
    std::cout << "bye -> " << tree.match(string("bye")) << std::endl;
    std::cout << "by -> " << tree.match(string("by")) << std::endl;


    /* matchText() is used to pass in a text and fetch the indexes of the matched patterns. */
    trie pMatching({string("ATCG"), string("GGGT")});
    auto pos = pMatching.matchText(string("AATCGGGTTCAATCGGGGT"));

    /* The given text matches the stored patterns at the following indexes */
    std::cout << "\nThe patterns have been found at - " << std::endl;
    for(auto p : pos)
        std::cout << p << std::endl;

    return 0;
}
