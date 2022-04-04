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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *second = head, *tracker = head;
        
        int kCopy = k;
        while(kCopy > 1 && first) {
            first = first->next;
            tracker = tracker->next;
            kCopy--;
        }
        
        while(tracker->next) {
            tracker = tracker->next;
            second = second->next;
        }
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        return head;
    }
    
};