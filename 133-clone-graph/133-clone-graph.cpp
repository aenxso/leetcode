/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // create hashmap which maps original node to clone node
        // bfs to explore nodes and their edges
        
        if(!node) return NULL;
        unordered_map<Node*, Node*> clone;
        Node* copy = new Node(node->val, {}); // create a start node
        clone[node] = copy;                   // map the start node
        queue<Node*> q;
        q.push(node);                         // add original start to queue to explore
        
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for(Node* neighbour : cur->neighbors) {
                // if it's not in the map, add it and add to queue to explore
                if(clone.find(neighbour) == clone.end()) {
                    clone[neighbour] = new Node(neighbour->val, {});
                    q.push(neighbour);
                }
                clone[cur]->neighbors.push_back(clone[neighbour]); // link edges
            }
        }
        return copy;
    }
};