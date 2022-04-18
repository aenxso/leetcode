/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        
        while(node || !stk.empty()) {
            while(node) {
                stk.push(node);
                node = node->left; // go all the way to the left most node (smallest value)
            }
            node = stk.top();
            if(--k == 0) return node->val;
            stk.pop();
            node = node->right;
        }
        return 0;
    }
};