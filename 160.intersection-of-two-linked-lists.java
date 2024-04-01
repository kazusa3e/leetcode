/*
 * @lc app=leetcode id=160 lang=java
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode iterA = headA, iterB = headB;
        int sizeA = 0, sizeB = 0;
        while (iterA != null) {
            sizeA += 1;
            iterA = iterA.next;
        }
        while (iterB != null) {
            sizeB += 1;
            iterB = iterB.next;
        }
        iterA = headA;
        iterB = headB;
        if (sizeA > sizeB) {
            int n = sizeA - sizeB;
            while (n != 0) {
                iterA = iterA.next;
                n -= 1;
            }
        } else {
            int n = sizeB - sizeA;
            while (n != 0) {
                iterB = iterB.next;
                n -= 1;
            }
        }
        while (iterA != null) {
            if (iterA == iterB) {
                return iterA;
            }
            iterA = iterA.next;
            iterB = iterB.next;
        }
        return null;
    }
}
// @lc code=end
