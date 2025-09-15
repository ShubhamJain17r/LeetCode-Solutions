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
        if (k == 0 || !head || !(head -> next)) return head;
        int len = 1;
        ListNode* temp = head;
        while (temp -> next){
            temp = temp -> next;
            len++;
        }
        cout<<len<<endl;
        k %= len;
        cout<<k<<endl;
        if (!k) return head; 
        ListNode* prev = nullptr;

        temp = head;
        while (temp -> next){
            if (prev) prev = prev -> next;
            if (k == 1){
                prev = head;
            }
            k--;
            temp = temp->next;
        }
        // cout<<temp -> val<<" "<<prev -> val<<endl;
        temp -> next = head;
        head = prev -> next;
        prev -> next = nullptr;
        return head;
    }
};
