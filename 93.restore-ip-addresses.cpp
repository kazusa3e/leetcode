/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start

#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<int> bag_;
    vector<string> results_;
    string s_;

    string join(const vector<int> &fragments) {
        assert(fragments.size() == 4);
        ostringstream oss;
        oss << to_string(fragments[0]) << "."
            << to_string(fragments[1]) << "."
            << to_string(fragments[2]) << "."
            << to_string(fragments[3]);
        return oss.str();
    }

    void backtracking(string::iterator pos) {
        if (pos == s_.end()) {
            if (bag_.size() == 4) {
                results_.push_back(join(bag_));
            }
            return;
        }
        if (bag_.size() > 4) return;
        for (auto iter = pos + 1; iter <= s_.end(); ++iter) {
            if (iter - pos > 1 && *pos == '0') continue;
            int n = stoul(string {pos, iter});
            if (n > 255UL) return;
            bag_.push_back(n);
            backtracking(iter);
            bag_.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        s_ = s;
        backtracking(s_.begin());
        return results_;
    }
};
// @lc code=end
