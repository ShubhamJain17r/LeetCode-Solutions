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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int prev = -101;

        for (ListNode* itr = head; itr; itr = itr->next) {
            if (prev == -101 || itr -> val != prev) {
                prev = itr -> val;
                temp -> next = new ListNode(prev);
                temp = temp -> next;
            }
        }
        temp -> next = nullptr;
        return dummy -> next;
    }
};
