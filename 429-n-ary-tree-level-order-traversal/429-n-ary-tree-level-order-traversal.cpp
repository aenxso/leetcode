/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            vector<int> level; // create vector for current level to push to final ans
            int n = q.size();
            for(int i = n; i >= 1; i--) {
                Node* curr = q.front(); 
                q.pop();
                level.push_back(curr->val);
                for(Node* child : curr->children) {
                    q.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};