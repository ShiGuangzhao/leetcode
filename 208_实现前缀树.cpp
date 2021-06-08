#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *search_prefix(string &str) {
        auto node = this;
        for(auto c: str) {
            c = c - 'a';
            if(node->children[c] == nullptr) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie(): children(26, nullptr), isEnd(false) {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for(auto c: word) {
            c = c - 'a';
            if(node->children[c] == nullptr) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = search_prefix(word);
        return node != nullptr and node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search_prefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
