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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();

        ListNode* temp = dummy;
        for (ListNode* it = head; it; it = it -> next) {
            if (it -> val != val) {
                temp -> next = it;
                temp = temp -> next;
            }
        }
        temp -> next = nullptr;

        return dummy -> next;
    }
};
