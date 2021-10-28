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

// recursion
// if(root1->left/right && root2->left/right) root1->left->val += root2->left->val (or right)
//      else if !root1 -- root1->val = root2->val
//      else if !root2 -- do nothing
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        
        if(!r1 && !r2) return NULL;
        
        if(r1 && r2) {
            r1->val += r2->val; // change nodes on one tree
            r1->left = mergeTrees(r1->left, r2->left);
            r1->right = mergeTrees(r1->right, r2->right);
        } else {
            return r1 ? r1 : r2; // if one node doesn't exist, use the other
        }
        
        return r1; // return now altered 'original' tree
    }
};

//         // experimenting

//         if(r1->left && r2->left) {
//             r1->left = merger(r1->left, r2->left);
//             r1->val += r2->val;
//         } else if(!r1 && r2) {
//             r1->left = r2->left;
//         }
        
//         if(r1->right && r2->right) {
//             r1->right = merger(r1->right, r2->right);
//             r1->val += r2->val;
//         } else if(!r1 && r2) {
//             r1->right = r2->right;
//         }
