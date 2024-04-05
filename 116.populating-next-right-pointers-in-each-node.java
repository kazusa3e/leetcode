/*
 * @lc app=leetcode id=116 lang=java
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public Node connect(Node root) {
        Queue<Node> queue = new ArrayDeque<>();
        if (root == null) {
            return null;
        }
        queue.add(root);
        while (!queue.isEmpty()) {
            Node prev = null;
            for (int sz = queue.size(); sz != 0; --sz) {
                Node curr = queue.remove();
                if (curr.left != null)
                    queue.add(curr.left);
                if (curr.right != null)
                    queue.add(curr.right);
                if (prev != null) {
                    prev.next = curr;
                }
                prev = curr;
            }
        }
        return root;
    }
}
// @lc code=end
