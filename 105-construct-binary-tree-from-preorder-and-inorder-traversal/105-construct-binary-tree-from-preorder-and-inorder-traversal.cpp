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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, int> map;
        for(int i = 0; i < in.size(); i++){
            map[in[i]] = i;
        }
        return splitTree(pre, map, 0, 0, in.size() - 1);
    }
    
private:
    TreeNode* splitTree(vector<int>& pre, unordered_map<int, int>& map, int pix, int ileft, int iright) {
        int rval = pre[pix], imid = map[rval];
        TreeNode* root = new TreeNode(rval);            
        if(imid > ileft) {
            root->left = splitTree(pre, map, pix + 1, ileft, imid - 1);
        }
            
        if(imid < iright) {
            root->right = splitTree(pre, map, pix + imid - ileft + 1, imid + 1, iright);
        }
           
        return root;
    }
};