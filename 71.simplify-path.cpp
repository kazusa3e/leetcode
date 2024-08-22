/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start

#include <string>
#include <deque>
#include <vector>
#include <regex>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        auto dirs = split(path);
        deque<string> de;
        for (auto el : dirs) {
            if (el == ".") continue;
            else if (el == "..") { if (!de.empty()) de.pop_back(); }
            else de.push_back(el);
        }
        string ret = "/";
        if (de.empty()) return ret;
        for (auto el : de) {
            ret += el;
            ret += "/";
        }
        ret.pop_back();
        return ret;
    }

    vector<string> split(const string &path) {
        vector<string> ret;
        regex pattern {"([a-zA-Z0-9\\._]+)"};
        for (auto iter = sregex_iterator(path.begin(), path.end(), pattern); iter != sregex_iterator{}; ++iter) {
            ret.push_back(iter->str());
        }
        return ret;
    }
};
// @lc code=end
