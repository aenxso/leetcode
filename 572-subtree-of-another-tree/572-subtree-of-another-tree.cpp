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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) {
            return false;
        } else if(same(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // if previous level wasn't correct, try the next level
        }
    }
    
private:
    bool same(TreeNode* root, TreeNode* s) {
        if(!root || !s) {
            return !root && !s; // remember to not just return false here - check if both are null, could be true
        } else if(root->val == s->val) {
            return same(root->left, s->left) && same(root->right, s->right);
        } else {
            return false;
        }
    }
};