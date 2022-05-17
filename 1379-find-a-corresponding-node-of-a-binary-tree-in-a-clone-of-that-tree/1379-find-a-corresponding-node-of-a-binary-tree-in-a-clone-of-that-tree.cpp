/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // pre-order DFS - not okay for duplicates but faster because it stops once the desired node is found
        return dfs(cloned, target);
    }
    
    TreeNode* dfs(TreeNode* cloned, TreeNode* target) {
        if(!cloned) return NULL;
        if(cloned->val == target->val) return cloned;
        
        auto left = dfs(cloned->left, target);
        if(left) return left;
        
        auto right = dfs(cloned->right, target);
        return right;
    }
};