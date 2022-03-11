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
    ListNode* rotateRight(ListNode* head, int k) {
        // create fast pointer to get k steps ahead of slow pointer
        // if k > length of list and we are moving fast k times, then we will reach null
        //   so return fast to head if fast == NULL somewhere in the loop. Also
        //   keep a counter that increments every time fast moves up -- this way we can get
        //   the length of the list and modify k so we don't need to uselessly return fast to head
        //   more times than necessary - only the first time
        // once we have new end node, point end->next to head (creates a circle list)
        // create new head at slow
        // point slow->next at null (disconnects circle list)
        
        if(!head || k == 0) return head;
        ListNode *slow = head, *fast = head;
        int len = 0; 
        
        // move fast pointer k steps ahead of slow
        while(k) {
            fast = fast->next;
            len++;
            k--;
            if(!fast) {
                fast = head;
                k %= len;
            }
        }
        // move both to get proper placement for slow pointer for new head
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        ListNode *newHead = slow->next;
        slow->next = NULL;
        
        return newHead;
        
    }
};