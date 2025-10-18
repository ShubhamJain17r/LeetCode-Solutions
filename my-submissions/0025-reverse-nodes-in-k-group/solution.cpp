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
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = end;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;

        // check if there are at least k nodes left
        for (int i = 0; i < k; i++) {
            if (!node) return head; // not enough nodes, return as-is
            node = node->next;
        }

        // reverse first k nodes
        ListNode* newHead = reverse(head, node);

        // recursively process next group
        head->next = reverseKGroup(node, k);

        return newHead;
    }
};

