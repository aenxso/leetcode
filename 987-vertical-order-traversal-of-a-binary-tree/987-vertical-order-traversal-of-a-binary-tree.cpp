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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // use multiset to handle duplicates in input
        
        map<int, map<int, multiset<int>>> map;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()) {
            root = q.front().first;
            int x = q.front().second.first, y = q.front().second.second; 
            q.pop();
            map[x][y].insert(root->val);
            if(root->left) q.push({root->left, {x - 1, y + 1}});
            if(root->right) q.push({root->right, { x + 1, y + 1}});
        }
        
        for(auto x : map) {
            vector<int> col;
            for(auto y : x.second) {
                for(auto elem : y.second) {
                    col.push_back(elem);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};