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
#include <queue>

using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        queue<Node *> qu;
        qu.push(root);
        int depth = 0;
        while (!qu.empty()) {
            depth += 1;
            for (int sz = qu.size(); sz != 0; --sz) {
                Node *node = qu.front(); qu.pop();
                vector<Node *> children = node->children;
                for_each(children.begin(), children.end(), [&qu](Node *n) {
                    qu.push(n);
                });
            }
        }
        return depth;
    }
};
// @lc code=end
