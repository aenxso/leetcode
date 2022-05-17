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
        // DFS approach - okay for duplicates
        
        if(!original) return NULL;
        if(original == target) return cloned;
        
        // check left subtree
        auto left = getTargetCopy(original->left, cloned->left, target);
        if(left) return left;
        
        //check right subtree
        auto right = getTargetCopy(original->right, cloned->right, target);
        return right;
    }
};