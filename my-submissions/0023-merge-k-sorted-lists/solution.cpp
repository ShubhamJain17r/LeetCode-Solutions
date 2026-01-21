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
    struct comp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return (l1 -> val) > (l2 -> val);
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (ListNode* list : lists) {
            if (list)
                pq.push(list);
        }
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while (!pq.empty()) {
            ListNode* list = pq.top(); pq.pop();
            if (list -> next) pq.push(list -> next);
            temp -> next = list;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};
