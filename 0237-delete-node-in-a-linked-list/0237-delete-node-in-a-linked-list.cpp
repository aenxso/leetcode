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
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next; //placeholder for the node we're deleting
        node->val = node->next->val; //'move' current node up one spot by copying next val
        node->next = node->next->next; //don't need duplicate vals, so make next it's next
        delete tmp; //delete the node
    }
};