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
        if(!head) return NULL;
        
        // create a fast pointer which is n nodes ahead of slow pointer
        ListNode *fast = head, *slow = head;
        while(n--) {
            fast = fast->next;
        }
        
        if(fast == NULL) return head->next; //if n == length of list, delete head and return next node
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* toDelete = slow->next; // pointer to refer back to node to be deleted
        slow->next = slow->next->next; // skip over toDelete node - 'deleting' it
        delete toDelete; // actually delete it from memory
        return head;
    }
};
