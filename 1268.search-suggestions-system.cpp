/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start

#include <vector>
#include <string>
#include <memory>
#include <array>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
class Solution {
private:
    struct trie_node {
        array<unique_ptr<trie_node>, 26> child;
        bool is_end { false };
    };
private:
    unique_ptr<trie_node> root { make_unique<trie_node>() };

private:
    void add(const string &s) {
        auto iter = root.get();
        for (const auto ch : s) {
            if (iter->child[ch - 'a'] == nullptr) {
                iter->child[ch - 'a'] = make_unique<trie_node>();
            }
            iter = iter->child[ch - 'a'].get();
        }
        iter->is_end = true;
    }

    void traverse(const trie_node *iter, string &prefix, vector<string> &&ret) const {
        if (ret.size() == 3) return;
        if (iter->is_end) ret.push_back(prefix);

        for (unsigned ix = 0; ix != 26; ++ix) {
            if (iter->child[ix] != nullptr) {
                prefix += (char) ('a' + ix);
                traverse(iter->child[ix].get(), prefix, std::move(ret));
                prefix.pop_back();
            }
        }
    }


public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (const auto &s : products) add(s);
        vector<vector<string>> ret;
        string prefix; auto iter = root.get();
        for (unsigned ix = 0; ix != searchWord.size(); ++ix) {
            if (iter == nullptr) { ret.push_back({}); continue; }
            prefix += searchWord[ix]; iter = iter->child[searchWord[ix] - 'a'].get();
            if (iter == nullptr) { ret.push_back({}); continue; }
            vector<string> curr;
            traverse(iter, prefix, std::move(curr));
            ret.push_back(std::move(curr));
        }
        return ret;
    }
};
// @lc code=end
