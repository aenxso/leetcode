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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;
        ListNode *tmp = head;
        while(tmp) {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(nums.begin(), nums.end());
        tmp = head;
        int i = 0;
        while(tmp) {
            tmp->val = nums[i++];
            tmp = tmp->next;
        }
        return head;
    }
};