/*
 * @lc app=leetcode id=559 lang=java
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int maxDepth(Node root) {
        if (root == null)
            return 0;
        Queue<Node> queue = new ArrayDeque<>();
        int depth = 0;
        queue.add(root);
        while (!queue.isEmpty()) {
            depth += 1;
            for (int sz = queue.size(); sz != 0; --sz) {
                Node n = queue.remove();
                for (Node child : n.children) {
                    if (child != null)
                        queue.add(child);
                }
            }
        }
        return depth;
    }
}
// @lc code=end
