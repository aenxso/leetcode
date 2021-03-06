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
    int kthSmallest(TreeNode* root, int k) {
        // iterative approach
        // create a stack of type TreeNode* and store the nodes from root->leftmost
        // pop stack k times by the time we reach end of BST and use newly created node
        //  to traverse to check the right child (completes the inorder traversal, otherwise values would be out of order)
        
        stack<TreeNode*> stk;
        TreeNode* node = root;
        
        while(node || !stk.empty()) {
            while(node) {
                stk.push(node);
                node = node->left; // go all the way to the left most node (smallest value)
            }
            node = stk.top();
            if(--k == 0) return node->val; // only traverse k times
            stk.pop();
            node = node->right; // check the right child to keep inorder traversal
        }
        return 0;
    }
};