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
    int widthOfBinaryTree(TreeNode* root) {
        // use heap indexing
        // left child is always parent * 2. Right child is always parent * 2 + 1, 
        //   regardless of whether these nodes exist or not.
        // at each node, check distance between leftmost and rightmost node and compare to current maxWidth
        
        if(!root) return 0;
        unsigned long long int maxWidth = 0; // use ulli to avoid overflow
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while(!q.empty()) {
            unsigned long long int l = q.front().second, r = l; // right starts at the same place as l
            for(int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if(node->left) q.push(pair<TreeNode*, int>(node->left, r * 2));
                if(node->right) q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
            }
            maxWidth = max(maxWidth, r + 1 - l);
        }
        return maxWidth;
    }
};