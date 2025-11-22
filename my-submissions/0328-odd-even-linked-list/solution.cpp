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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next || !head -> next -> next) return head;
        ListNode* prev = head;
        ListNode* temp = head -> next;
        ListNode* ahead = temp -> next;
        ListNode* even = temp;
        bool sizeEven = true;
        while (ahead) {
            prev -> next = ahead;
            prev = temp;
            temp = ahead;
            ahead = ahead -> next;
            sizeEven = !sizeEven;
        }
        if (!sizeEven) {
            prev -> next = nullptr;
            temp -> next = even;
        }
        else {
            prev -> next = even;
        }
        return head;
    }
};
