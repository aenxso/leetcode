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
    TreeNode* increasingBST(TreeNode* root) {
        // go all the way to the left then append the nodes to a new tree, always going to the right
        
        if(!root) return NULL;
        
        increasingBST(root->left);
        node->right = new TreeNode(root->val);
        node = node->right;
        increasingBST(root->right);
        
        return newRoot->right;
    }

private:
    // declare these outside recursion otherwise new ones will be made everytime and nothing will join together
    TreeNode* node = new TreeNode(0); 
    TreeNode* newRoot = node;
};