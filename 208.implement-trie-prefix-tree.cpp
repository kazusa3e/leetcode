/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

#include <string>
#include <array>
#include <memory>

using namespace std;

class Trie {
private:
    struct trie_node {
        array<unique_ptr<trie_node>, 26> children {};
        bool is_word_end { false };
    };

private:
    unique_ptr<trie_node> root { make_unique<trie_node>() };

public:
    Trie() {}
    
    void insert(string word) {
        auto iter = root.get();
        for (const auto ch : word) {
            if (iter->children[ch - 'a'] == nullptr) {
                iter->children[ch - 'a'] = make_unique<trie_node>();
            }
            iter = iter->children[ch - 'a'].get();
        }
        iter->is_word_end = true;
    }
    
    bool search(string word) {
        auto iter = root.get();
        for (const auto ch : word) {
            if (iter->children[ch - 'a'] == nullptr) return false;
            iter = iter->children[ch - 'a'].get();
        }
        return (iter->is_word_end == true);
    }
    
    bool startsWith(string prefix) {
        auto iter = root.get();
        for (const auto ch : prefix) {
            if (iter->children[ch - 'a'] == nullptr) return false;
            iter = iter->children[ch - 'a'].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
