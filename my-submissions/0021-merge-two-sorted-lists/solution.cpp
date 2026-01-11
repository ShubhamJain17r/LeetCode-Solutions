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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* dummy_temp = dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 && temp2) {
            if (temp1 -> val < temp2 -> val) {
                dummy_temp -> next = temp1;
                temp1 = temp1 -> next;
            }
            else {
                dummy_temp -> next = temp2;
                temp2 = temp2 -> next;
            }
            dummy_temp = dummy_temp -> next;
        }
        if (temp1) {
            dummy_temp -> next = temp1;
        }
        else {
            dummy_temp -> next = temp2;
        }
        return dummy -> next;
        
    }
};
