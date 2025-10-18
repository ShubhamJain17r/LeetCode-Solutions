/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* temp = node -> next;

        while (temp -> next) {
            prev -> val = temp -> val;
            prev = prev -> next; 
            temp = temp -> next;
        }
        prev -> val = temp -> val;
        prev -> next = nullptr;
    }
};
