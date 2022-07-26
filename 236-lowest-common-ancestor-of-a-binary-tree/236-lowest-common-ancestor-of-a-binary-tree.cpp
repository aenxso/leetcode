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
        // naive approach
        // store the path to both nodes in vector
        // go through vector and find the common ancestor
        
        if(!root) return {};
        TreeNode* ans;
        
        vector<TreeNode*> path1, path2;
        
        getPath(root, path1, p->val);
        getPath(root, path2, q->val);
        
        int n = min(path1.size(), path2.size());
        
        for(int i = 0; i < n; i++) { // get the lowest by continuously going through the vector until we reach the end of the shorter path
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
        
        path.push_back(root); // add current node to path
        
        if(root->val == x) return true; // if x is found, return
        
        if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true; // recurse through left and right subtree
        
        path.pop_back();
        
        return false;
    }
};