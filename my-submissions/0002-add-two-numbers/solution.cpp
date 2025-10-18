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
        ListNode sum;
        ListNode* curr = &sum;

        int carry = 0, num1, num2;

        while (l1 || l2 || carry){
            if (l1){
                num1 = l1 -> val;
                l1 = l1 -> next;
            }
            else 
                num1 = 0;
            if (l2) {
                num2 = l2 -> val;
                l2 = l2 -> next;
            }
            else
                num2 = 0;
            int sum = num1 + num2 + carry;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            carry = sum / 10;
        }
        return sum.next;
    }
};
