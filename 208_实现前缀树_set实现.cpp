#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Trie {
private:
    unordered_set<string> words;
    unordered_set<string> prefixs;

public:
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        words.insert(word);
        for(auto i = 1; i <= word.size(); ++i) {
            prefixs.insert(word.substr(0, i));
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return words.count(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixs.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
