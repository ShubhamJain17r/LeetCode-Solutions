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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !(head -> next)) return nullptr;

        ListNode* curr = head;
        ListNode* end = nullptr;

        int count = 0;

        while (curr->next){
            count++;
            if (end) end = end -> next;

            if (count == n){
                end = head;
            }

            curr = curr -> next;
        }
        if (end == nullptr) return head -> next;
        end -> next = end -> next -> next;
        return head;
    }
};
