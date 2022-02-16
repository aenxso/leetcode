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
    ListNode* swapPairs(ListNode* head) {
        // tracker a and b, and one for tracking 2 spots over. tmp for keeping a''s spot
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode *a = head, *b = head->next;
        
        while(b && b->next) {
            ListNode *tracker = b->next->next;
            ListNode *tmp = b->next;
            a->next = tmp;
            tmp->next = b;
            b->next = tracker;
            a = tmp->next;
            b = tracker;
        }
        return head->next;
    }
};