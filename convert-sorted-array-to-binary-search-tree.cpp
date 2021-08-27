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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrangeBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* arrangeBST(vector<int>& nums, int start, int end) {
        /* point is to recursively pick new root of subtrees*/
        //base case
        if(end < start) return NULL;
        
        int middle = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]); //create new root of subtree
        root->left = arrangeBST(nums, start, middle-1);
        root->right = arrangeBST(nums, middle+1, end);
        
        return root;
    }
};
