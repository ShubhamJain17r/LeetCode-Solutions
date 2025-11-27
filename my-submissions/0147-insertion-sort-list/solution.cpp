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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(INT_MIN); // Dummy head
        dummy->next = head;

        ListNode* prev = head;       // Last sorted node
        ListNode* curr = head->next; // Node to insert

        while (curr) {
            if (curr->val >= prev->val) {
                // Already in correct order
                prev = curr;
                curr = curr->next;
            } else {
                // Remove curr from list
                prev->next = curr->next;

                // Find position to insert
                ListNode* temp = dummy;
                while (temp->next->val < curr->val) {
                    temp = temp->next;
                }

                // Insert curr after temp
                curr->next = temp->next;
                temp->next = curr;

                // Move curr forward
                curr = prev->next;
            }
        }

        return dummy->next;
    }
};

