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
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        ListNode* nth = &dummy;

        while (curr -> next){
            curr = curr -> next;
            if (--n < 0)
                nth = nth -> next;
        }
        ListNode* toDelete = nth -> next;
        nth -> next = nth -> next -> next;
        delete toDelete;
        return dummy.next;
    }
};
