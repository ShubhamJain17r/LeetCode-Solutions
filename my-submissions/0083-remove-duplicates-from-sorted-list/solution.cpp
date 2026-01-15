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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head -> next) return head;
        int curr = -101;
        ListNode* temp = head;
        ListNode* dummy = new ListNode();
        ListNode* temp2 = dummy;
        while (temp) {
            if (temp -> val != curr) {
                curr = temp -> val;
                temp2 -> next = temp;
                temp2 = temp;
            }
            temp = temp -> next;
        }
        temp2 -> next = nullptr;
        return dummy -> next;
    }
};
