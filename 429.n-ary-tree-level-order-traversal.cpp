/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
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
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            for (int sz = q.size(); sz != 0; --sz) {
                Node *node = q.front();
                q.pop();
                auto children = node->children;
                for_each(children.begin(), children.end(), [&q](Node *n) {
                    q.push(n);
                });
                vec.push_back(node->val);
            }
            ret.push_back(vec);
        }
        return ret;
    }
};
// @lc code=end
