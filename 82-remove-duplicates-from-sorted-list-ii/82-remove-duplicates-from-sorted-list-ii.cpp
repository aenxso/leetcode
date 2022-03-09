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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = prev->next;
        
        while(cur) {
            ListNode *checker = cur->next;
            if(checker && checker->val == cur->val) {
                auto value = checker->val;
                while(checker && checker->val == value) {
                    ListNode *del = checker;
                    checker = checker->next;
                    delete del;
                }
                cur = checker;
                prev->next = cur;
            } else {
                prev = cur;
                cur = checker;
            }
        }
        return dummy.next;
    }
};