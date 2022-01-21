/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) { // cycle found
                slow = head;   // reset slow to beginning of list
                while(slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};