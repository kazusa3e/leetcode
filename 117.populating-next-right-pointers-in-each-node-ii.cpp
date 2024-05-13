/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <queue>

using namespace std;

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *prev = nullptr;
            for (int sz = q.size(); sz != 0; --sz) {
                Node *node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                if (prev != nullptr) {
                    prev->next = node;
                }
                prev = node;
            }
            prev->next = nullptr;
        }
        return root;
    }
};
// @lc code=end
