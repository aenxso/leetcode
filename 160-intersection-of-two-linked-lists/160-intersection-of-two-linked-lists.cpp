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
        int lenA = Length(headA), lenB = Length(headB);
        int diff = abs(lenA - lenB);
        AdvanceByK(diff, lenA > lenB ? &headA : &headB);
        
//         if(lenA < lenB) swap(headA, headB);
        
//         while(diff--) {
//             headA = headA->next;
//         }
        
        while (headA && headB && (headA != headB)) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA; //nullptr implies no overlap
    }
    
    int Length(ListNode* list) {
        int len = 0;
        while (list) {
            ++len;
            list = list->next;
        }
        return len;
    }
    
    void AdvanceByK(int k, ListNode** list) {
        while(k--) {
            *list = (*list)->next;
        }
    }
};