/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        vector<Node *> children = root->children;
        vector<int> depths;
        transform(
            children.begin(), children.end(),
            back_inserter(depths),
            [&](Node *node) { return maxDepth(node); }
        );
        if (depths.size() == 0) return 1;
        return 1 + *max_element(depths.begin(), depths.end());
    }
};
// @lc code=end
