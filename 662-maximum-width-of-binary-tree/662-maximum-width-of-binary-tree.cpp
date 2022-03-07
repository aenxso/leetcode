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
        // l and r are used to keep track of indexes, basically every node is an index
        // left child is always parent * 2. Right child is always parent * 2 + 1, 
        //   regardless of whether these nodes exist or not.
        // at each node, check distance between leftmost and rightmost node and compare to current maxWidth
        /*
               @aryanttripathi
                            Index
                                 12   (1)            Width here = 1
								/  \
							   /    \
			       Index	  /      \      Index     
				   (2)	    23       34      (3)     Width here = (3 - 2 + 1) = 2
							/ \       /\
						   /   \     /  \
						  76 null  null  64    
			       Index (4)  (5)  (6)   (7)		Width here = (7 - 4 + 1) = 4	  
        
        */
        
        if(!root) return 0;
        unsigned long long int maxWidth = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        
        while(!q.empty()) {
            unsigned long long int l = q.front().second, r = l; // right starts at the same place as left
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if(node->left)q.push(pair<TreeNode*, int>(node->left, r * 2));
                if(node->right)q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
            }
            maxWidth = max(maxWidth, r - l + 1);
        }
        return maxWidth;
    }
};