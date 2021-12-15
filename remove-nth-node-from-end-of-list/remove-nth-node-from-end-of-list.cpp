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
        
        ListNode *fast = head, *slow = head;
        
        while(n) { // increment faster node by n spaces
            fast = fast->next;
            n--;
        }
        
        if(fast == NULL) return head->next; // if n == length of list delete the head 
        
        while(fast->next) { // increment both pointers till end of list is reached -- slow->next will now be nth node from end
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next; // skip over node to be deleted (reroute links)
        delete toDelete; // actually delete it
        
        return head;
    }
};