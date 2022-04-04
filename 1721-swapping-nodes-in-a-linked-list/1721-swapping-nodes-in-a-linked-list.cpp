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
        // create two pointers to track each position
        // move the first pointer up k spaces, and a tracker pointer - both start from head
        // move tracker up until the end and move second pointer along with it - second is k nodes away from tracker
        //   and when tracker reaches the end of the list, second will be k spaces from the end
        // swap the values once pointers are in place
        
        ListNode *first = head, *second = head, *tracker = head;
     
        while(k > 1 && first) {
            first = first->next;
            tracker = tracker->next;
            k--;
        }
        
        while(tracker->next) {
            tracker = tracker->next;
            second = second->next;
        }
        
        swap(first->val, second->val);
        return head;
    }
    
};