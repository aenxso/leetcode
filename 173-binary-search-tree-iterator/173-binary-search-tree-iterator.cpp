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
class BSTIterator {
public:
    // use a stack to accomplish task in O(h) memory (height of tree)
    // use partial inorder traversal
    
    BSTIterator(TreeNode* root) {
        leftTree(root);
    }
    
    void leftTree(TreeNode* root) {
        TreeNode *node = root;
        while(node) {
            pointers.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode *node = pointers.top();
        pointers.pop();
        if(node->right) { // if right node exists
            leftTree(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return pointers.empty() ? false : true;
    }
    
private:
    stack<TreeNode*> pointers;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */