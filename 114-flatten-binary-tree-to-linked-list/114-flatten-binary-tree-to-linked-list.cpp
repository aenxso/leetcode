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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);  // go all the way to the left tree
        flatten(root->right); // once reached the bottom of the left tree, go to the right children
        
        TreeNode *tmp = root->right; // create tmp node to store the right subtree
        
        root->right = root->left; // make the root point to the left tree, now making it it's right subtree (moving the left over to the right)
        root->left = NULL;        // clear the left subtree
        
        while (root->right) {   // move the pointer for root all the way down to the last newly placed right node
            root = root->right; //  so when we re-attach the right subtree it's attached at the bottom of the 'list'
        }
        
        root->right = tmp; // attach the stored original right subtree
    }
};