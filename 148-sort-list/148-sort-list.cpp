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
    ListNode* sortList(ListNode* head) {
        // recursively divide list into two parts and sort, then merge together
        
        if(!head || !head->next) return head;
        ListNode *fast = head->next, *slow = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // divide the list in 2
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }
    
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode *cur = &tmp;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if(l1) {
            cur->next = l1; 
        } else if(l2) {
            cur->next = l2;
        }
        
        return tmp.next;
    }
};