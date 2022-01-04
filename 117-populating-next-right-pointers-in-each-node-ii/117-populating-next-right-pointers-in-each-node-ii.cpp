/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // create dummy node to keep track of where 'next' should be
        
        
        if(!root) return NULL;
        Node *p = root->next;
        
        while(p) {
            if(p->left) { // choose left first if possible since that is the closer node that left subtree should be pointing to
                p = p->left;
                break;
            }
            if(p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        
        
        if(root->right) {
            root->right->next = p;
        }
        
        if(root->left) {
            root->left->next = root->right ? root->right : p;
        }
      
        
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};