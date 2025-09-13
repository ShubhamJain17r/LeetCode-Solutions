/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 || l2 || carry){
            int a = l1 ? l1 -> val : 0;
            int b = l2 ? l2 -> val : 0;
            int s = a + b + carry;

            carry = s / 10;

            temp -> next = new ListNode(s % 10);

            temp = temp -> next;

            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }

        ListNode* result = dummy -> next;
        delete dummy;

        return result;
    }
};
