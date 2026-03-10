/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode reverse(ListNode head){
        if (head == null || head.next == null) return head;
        ListNode prev = head;
        ListNode temp = head.next;
        ListNode ahead = head.next.next;
        prev.next = null;

        while (temp != null){
            temp.next = prev;
            prev = temp;
            temp = ahead;
            if (ahead != null) ahead = ahead.next;
        }
        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow != null && fast != null){
            if (slow.val != fast.val) return false;
            slow = slow.next;
            fast = fast.next;
        }
        return true;
    }
}
