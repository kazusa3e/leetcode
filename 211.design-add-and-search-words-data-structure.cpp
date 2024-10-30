/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

#include <string>
#include <array>
#include <memory>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class WordDictionary {
private:
    struct trie_node {
        array<unique_ptr<trie_node>, 26> child {};
        bool is_word { false };
    };

private:
    unique_ptr<trie_node> root { make_unique<trie_node>() };

public:
    WordDictionary() {}
    
    void addWord(string word) {
        auto iter = root.get();
        for (const auto ch : word) {
            if (iter->child[ch - 'a'] == nullptr) {
                iter->child[ch - 'a'] = make_unique<trie_node>();
            }
            iter = iter->child[ch - 'a'].get();
        }
        iter->is_word = true;
    }
    
    bool search(string word) const {
        return search(word, root.get());
    }

    bool search(string pattern, const trie_node *iter) const {
        if (iter == nullptr) return false;
        if (pattern.empty()) return iter->is_word;
        for (unsigned ix = 0; ix != pattern.size(); ++ix) {
            char ch = pattern[ix];
            if (ch == '.') {
                for (unsigned j = 0; j != 26; ++j) {
                    if (search(pattern.substr(ix + 1), iter->child[j].get())) return true;
                }
                return false;
            }
            if (iter->child[ch - 'a'] == nullptr) return false;
            iter = iter->child[ch - 'a'].get();
        }
        return iter->is_word;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
