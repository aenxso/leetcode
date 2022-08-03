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
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        return checkValid(root, NULL, NULL);
    }
    
private:
    bool checkValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        // keep track of a min and max to compare node values to
        // when going down left subtree, root->left will be the new root and we compare to original root (which is the max in left's case)
        // when going down right subtree, root->right will be the new root and we compare to original root (which is the min in right's case)
        // in left tree, we aren't comparing to a min value so min can be null
        //  - just check if the root is less than the max (original root)
        // in right tree, we aren't comparing to a max value so max can be null
        //  - just check if the root is greater than the min (original root)
        
        if(!root) return true;
        if((max && (root->val >= max->val)) || (min && (root->val <= min->val))) return false;
        return checkValid(root->left, min, root) && checkValid(root->right, root, max);
    }
};