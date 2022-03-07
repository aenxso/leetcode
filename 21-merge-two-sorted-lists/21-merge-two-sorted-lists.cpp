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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = NULL;
        ListNode* sorter = &dummy;
        
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                sorter->next = l1;
                l1 = l1->next;
            } else {
                sorter->next = l2;
                l2 = l2->next;
            }
            sorter = sorter->next; // remember to increment sorter otherwise we'll just keep overwriting the same value
        }
       
       sorter->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};