/*
 * @lc app=leetcode id=707 lang=java
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {

    static class Node {
        int val;
        Node prev;
        Node next;

        public Node(int val, Node prev, Node next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node sentinel;
    private int size;

    public MyLinkedList() {
        this.sentinel = new Node(-1, null, null);
        this.sentinel.prev = this.sentinel;
        this.sentinel.next = this.sentinel;
        this.size = 0;
    }

    private Node find(int index) {
        if (index < 0 || index >= this.size) {
            return null;
        }
        Node iter = this.sentinel;
        while (index != 0) {
            iter = iter.next;
            index -= 1;
        }
        return iter;
    }

    public int get(int index) {
        Node iter = find(index);
        if (iter == null) {
            return -1;
        }
        return iter.next.val;
    }

    public void addAtHead(int val) {
        Node node = new Node(val, this.sentinel, this.sentinel.next);
        this.sentinel.next.prev = node;
        this.sentinel.next = node;
        this.size += 1;
    }

    public void addAtTail(int val) {
        Node node = new Node(val, this.sentinel.prev, this.sentinel);
        this.sentinel.prev.next = node;
        this.sentinel.prev = node;
        this.size += 1;
    }

    public void addAtIndex(int index, int val) {
        if (index == this.size) {
            this.addAtTail(val);
            return;
        }
        Node node = find(index);
        if (node == null) {
            return;
        }
        Node n = new Node(val, node, node.next);
        node.next.prev = n;
        node.next = n;
        this.size += 1;
    }

    public void deleteAtIndex(int index) {
        Node node = find(index);
        if (node == null) {
            return;
        }
        if (this.size == 0) {
            return;
        }
        node.next = node.next.next;
        node.next.prev = node;
        this.size -= 1;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
// @lc code=end
