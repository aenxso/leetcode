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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return {};
        TreeNode* ans;
        
        vector<TreeNode*> path1, path2;
        
        getPath(root, path1, p->val);
        getPath(root, path2, q->val);
        
        int n = min(path1.size(), path2.size());
        
        for(int i = 0; i < n; i++) {
            if(path1[i] == path2[i]) {
                ans = path1[i]; 
            } else {
                break;
            }
        }
        
        return ans;
    }
    
private:
    bool getPath(TreeNode* root, vector<TreeNode*> &path, int x) {
        if(!root) return false;
        
        path.push_back(root);
        
        if(root->val == x) return true;
        
        if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true;
        
        path.pop_back();
        
        return false;
    }
};