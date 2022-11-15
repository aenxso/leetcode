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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        TreeNode *right = root, *left = root; // pointers to "halve" tree
        int r = 0, l = 0; // track height of left and right subtree
        
        // go all the way in both directions - check if height is the same at the end
        while(left) {
            l++;
            left = left->left;
        }
        while(right) {
            r++;
            right = right->right;
        }
        
        // height = 2^h - root
        if(l == r) return pow(2, l) - 1; 
        
        // if not even, return + 1 for the single node
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};