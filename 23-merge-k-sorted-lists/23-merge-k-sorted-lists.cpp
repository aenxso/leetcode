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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // create a helper function to merge two lists, continually delete 2 lists from original vector
        // after they've been sorted and merged
        // While this is happening, we are pushing the new sorted list onto the end of the original lists
        // - by the end of it, all mini lists will have been deleted and the only element will be the long, sorted list
        
        if(lists.empty()) return NULL;
        
        while(lists.size() > 1) {
            lists.push_back(merger(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    
private:
    ListNode* merger(ListNode *l1, ListNode *l2) { 
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode dummy = NULL;
        ListNode *sorter = &dummy;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                sorter->next = l1;
                l1 = l1->next;
            } else {
                sorter->next = l2;
                l2 = l2->next;
            }
            sorter = sorter->next;
        }
        
        sorter->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};