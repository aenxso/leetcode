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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // use a length function to get the length of each list
        // get the difference of the lengths and increment the longer list by the difference 
        //  then increment both lists till they reach the end and while they are not the same
        
        int lenA = getLength(headA), lenB = getLength(headB);
        int diff = abs(lenA - lenB);
        advanceByDiff(diff, lenA > lenB ? &headA : &headB);
        
        while(headA && headB && (headA != headB)) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA; // if null is returned there is no overlap
    }
    
private:
    int getLength(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    void advanceByDiff(int diff, ListNode** head) {
        while(diff) {
            diff--;
            *head = (*head)->next;
        }
    }
};