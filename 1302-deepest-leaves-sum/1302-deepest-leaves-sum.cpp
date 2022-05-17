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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int depth = getDepth(root);
        return getSum(root, depth);
    }
    
private:
    int getDepth(TreeNode *root) { // helper function to get depth of deepest leaves
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    
    int getSum(TreeNode *root, int depth) {
        if(!root) return 0;
        if(depth == 1) return root->val; // reached the lowest level
        return getSum(root->left, depth - 1) + getSum(root->right, depth - 1); // subract 1 from depth to get closer to the bottom from root
    }
};