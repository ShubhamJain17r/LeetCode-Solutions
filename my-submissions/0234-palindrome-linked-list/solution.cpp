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
    ListNode* reverse(ListNode* head){
        if (!head || !head -> next) return head;
        ListNode* prev = head;
        ListNode* temp = head -> next;
        ListNode* ahead = head -> next -> next;
        prev -> next = nullptr;

        while (temp){
            temp -> next = prev;
            prev = temp;
            temp = ahead;
            if (ahead) ahead = ahead -> next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow && fast){
            if (slow -> val != fast -> val) return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};
