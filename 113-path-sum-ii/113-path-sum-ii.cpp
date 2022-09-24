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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, int newtarget, vector<int>& path) {
        if(!root) return;
        path.push_back(root->val);
        newtarget -= root->val;           // new target = previous target - value of that node
        if(!root->left && !root->right) { // check whether leaf node or not
            if(newtarget == 0)            // add to ans if path is valid
                ans.push_back(path);
        } else {
            dfs(root->left, newtarget, path);
            dfs(root->right, newtarget, path);
        }
        path.pop_back();
    }
};