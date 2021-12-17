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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return merger(root1, root2);
    }
    
    TreeNode* merger(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return NULL;
        
        if(r1 && r2) {
            r1->val += r2->val;
            r1->left = merger(r1->left, r2->left);
            r1->right = merger(r1->right, r2->right);
        } else {
            return r1 ? r1 : r2;
        }
        
        return r1;
    }
};