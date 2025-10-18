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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* tail = head;
        int count = 0;

        while (temp){
            temp = temp -> next;
            count++;
        }

        k %= count;

        temp = head;

        while (temp -> next){
            temp = temp -> next;
            if (--k < 0){
                tail = tail -> next;
            }
        }
        temp -> next = head;
        head = tail->next;
        tail -> next = nullptr;
        return head;
    }
};
