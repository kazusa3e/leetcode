/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (unsigned ix = 1ull; ix <= n; ++ix) {
            if (ix % 3 == 0 && ix % 5 == 0) ret[ix - 1] = "FizzBuzz";
            else if (ix % 3 == 0) ret[ix - 1] = "Fizz";
            else if (ix % 5 == 0) ret[ix - 1] = "Buzz";
            else ret[ix - 1] = to_string(ix);
        }
        return ret;
    }
};
// @lc code=end
