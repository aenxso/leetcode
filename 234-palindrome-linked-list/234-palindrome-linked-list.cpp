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
    bool isPalindrome(ListNode* head) {
        
        /* COMMENTED OUT CODE IS MY FIRST SUBMISSION 
        - changed it to test speed/memory advantages 
        - not really any change */
        
        
        if(!head) return true;
        // int len = length(head) / 2; //get length of half of list 
        ListNode *first = head, *second = head;
        
        // while(len--) {
        //     second = second->next; //get second half iter to halfway point
        // }
        while(first && first->next) {
            first = first->next->next;
            second = second->next;
        }
        
        second = reverseList(second);
        first = head;
        
        while(first && second) {
            if(first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
    
    // int length(ListNode* list) { //calculate length of list
    //     int count = 0;
    //     while(list) {
    //         count++;
    //         list = list->next;
    //     }
    //     return count;
    // }
    
    ListNode* reverseList(ListNode* list) { //reverse list
        ListNode *dummy = NULL, *cur = list, *tmp = NULL;
        
        while(cur) {
            tmp = cur->next;
            cur->next = dummy;
            dummy = cur;
            cur = tmp;
        }
        return dummy;
    }
};