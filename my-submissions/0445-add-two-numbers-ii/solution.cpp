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
    ListNode* reverse(ListNode* head){
        if (!head || !head -> next) return head;
        ListNode* prev = head;
        ListNode* temp = prev -> next;
        ListNode* ahead = temp -> next;
        prev -> next = nullptr;
        while (temp){
            temp -> next = prev;
            prev = temp;
            temp = ahead;
            if (ahead) 
                ahead = ahead -> next;
        } 
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* add = &dummy;

        int carry = 0;
        l1 = reverse(l1);
        l2 = reverse(l2);

        while (l1 || l2 || carry){
            int num1 = l1 ? l1 -> val : 0;
            int num2 = l2 ? l2 -> val : 0;
            int sum = num1 + num2 + carry;
            add -> next = new ListNode(sum % 10);
            add = add -> next;
            carry = sum / 10;
            if (l1)
                l1 = l1 -> next;
            if (l2)
                l2 = l2 -> next;
        }
        return reverse(dummy.next);
    }
};
