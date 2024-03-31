/*
 * @lc app=leetcode id=24 lang=java
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null) {
            return head;
        }
        if (head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(-1, head);
        ListNode iter = dummy;
        while (iter != null && iter.next != null && iter.next.next != null) {
            ListNode p = iter.next;
            ListNode q = iter.next.next;
            ListNode t = iter.next.next.next;
            iter.next = q;
            q.next = p;
            p.next = t;
            iter = iter.next.next;
        }
        return dummy.next;
    }
}
// @lc code=end
