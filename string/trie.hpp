#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>

/* Declare the trieEdge data structure */
struct trieEdge;

/* Alias for a pointer to the trieEdge ds */
using trie_ptr = std::shared_ptr<trieEdge>;

/* Define the trieEdge ds */
struct trieEdge {
    std::unordered_map<char, trie_ptr> edges;
    bool leaf;
};

class trie {
    trie_ptr root;
public:
    trie();
    trie(const std::initializer_list<std::string>& patterns);
    void insert(const std::string& pattern);
    void remove(const std::string& pattern);
    bool match(const std::string& pattern);
    std::vector<size_t> matchText(const std::string& pattern);
};

/* Contructor - Initializes the root object */
trie::trie() {
    root = std::make_shared<trieEdge>();
}

/* Contructor - accepts a list of string patterns and adds to the tire */
trie::trie(const std::initializer_list<std::string>& patterns) : trie() {

    for(auto const & str : patterns)
        insert(str);
}

/* Inserts individual patterns in the trie */
void trie::insert(const std::string& pattern) {
    trie_ptr node = root;

    for(std::string::const_iterator ch = pattern.begin(); ch != pattern.end(); ++ch) {
        if(!node->edges[*ch])
            node->edges[*ch] = std::make_shared<trieEdge>();

        node = node->edges[*ch];
    }

    node->leaf = true;
}

/* Removes a pattern from the trie */
void trie::remove(const std::string& pattern) {
    trie_ptr node = root;

    for(const auto & ch : pattern) {
        if(!node->edges[ch])
            return;

        node = node->edges[ch];
    }

    node->leaf = false;
}

/* Checks if the given pattern is present in the trie or not */
bool trie::match(const std::string& pattern) {
    trie_ptr node = root;
    std::string::const_iterator ch = pattern.begin();

    while(ch != pattern.end()) {
        if(!node->edges[*ch])
            return false;

        node = node->edges[*ch];
        ch++;
    }

    if(node->leaf)
        return true;
}

/* Scans the given text for patterns stored - returns a vector of indices */
std::vector<size_t> trie::matchText(const std::string& pattern) {
    trie_ptr node;
    std::vector<size_t> index;

    for(std::string::size_type pIndex = 0; pIndex != pattern.size(); ++pIndex) {
        node = root;

        for(std::string::size_type cIndex = pIndex; cIndex != pattern.size(); ++cIndex) {
            if(!node->edges[pattern.at(cIndex)])
                break;

            node = node->edges[pattern.at(cIndex)];

            if(node->leaf) {
                index.push_back(pIndex);
                break;
            }
        }
    }

    return index;
}
