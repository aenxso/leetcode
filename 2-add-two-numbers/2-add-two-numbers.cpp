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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *temp = NULL;
        int carry = 0;         // need to account for carry since we are adding whole numbers
        
        while(l1 || l2) {      // OR since lists may be different lengths
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            
            if(sum > 9) {
                carry = sum / 10;
                sum %= 10;
            } else {
                carry = 0;     // need to reset carry every time, otherwise an old value may carry over into the end
            }
            
            if(head == NULL) { // if at the start of the new list
                head = new ListNode(sum);
                temp = head;
            } else {           // if list has already been established
                head->next = new ListNode(sum);
                head = head->next;
            }
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry) {
            head->next = new ListNode(carry);
        }
        
        return temp;
    }
};