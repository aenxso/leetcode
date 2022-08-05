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
    ListNode* oddEvenList(ListNode* head) {
        // basically keep skipping over the original next by one
        // this works by creating the correct starting position, ie. odd = head, even = heada->next;
        // remember to join odd and even lists at the end - create an evenHead to keep track of where odd->next should point to
        
        if(!head) return head;
        ListNode *even = head->next, *odd = head, *evenHead = even;
        
        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead; // attach end of odd list to the beginning of even list
        return head;
    }
};