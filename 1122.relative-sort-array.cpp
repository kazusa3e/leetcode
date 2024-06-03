/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start

#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s = {arr2.begin(), arr2.end()};
        map<int, int> m;  // value -> occurrences
        vector<int> others;
        for (auto elem: arr1) {
            if (auto pos = s.find(elem); pos != s.end()) m[elem] += 1;
            else others.push_back(elem);
        }

        vector<int> ret;
        for (auto elem : arr2) {
            vector<int> frag(m[elem], elem);
            copy(frag.begin(), frag.end(), back_inserter(ret));
        }
        sort(others.begin(), others.end());
        copy(others.begin(), others.end(), back_inserter(ret));
        return ret;
    }
};
// @lc code=end
