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
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists[0];
    }
    
private:
    ListNode* merge(ListNode *a, ListNode *b) {
        
        if(!a) return b;
        if(!b) return a;
        
        if(a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
    
};