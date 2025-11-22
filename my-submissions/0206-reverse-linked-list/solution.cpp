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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* prev = head;
        ListNode* temp = head -> next;
        ListNode* ahead = temp -> next;
        head -> next = nullptr;
        while (ahead) {
            temp -> next = prev;
            prev = temp;
            temp = ahead;
            ahead = ahead -> next;
        }
        temp -> next = prev;
        return temp;
    }
};
