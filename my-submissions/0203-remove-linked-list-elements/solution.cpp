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
        if (!head) return nullptr;

        ListNode* newHead = new ListNode();
        ListNode* prev = newHead;

        for (ListNode* temp = head; temp; temp = temp -> next) {
            if (temp -> val != val) {
                prev -> next = temp;
                prev = temp;
            }
        }
        prev -> next = nullptr;
        return newHead -> next;
    }
};
