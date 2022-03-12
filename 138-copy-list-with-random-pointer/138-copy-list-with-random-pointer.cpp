/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a hashmap which maps the original node to a newly created node
        // use one pass to create this map, note that new list has no connections yet (next/random)
        // on second pass, create the next and random links by utilizing the constant access 
        //   to a certain node in both lists. eg. map[clone]->next = map[original->next]
        //   rmbr map[original->next] is still pointing to the cloned list, so the deep copy properties still hold
        
        if(!head) return NULL;
        Node* itr = head; // create a node to iterate through list as needed
        unordered_map<Node*, Node*> map;
        
        // 1st pass - create a copy of each node which the original's value
        while(itr) {
            map[itr] = new Node(itr->val);
            itr = itr->next;
        }
        itr = head; // reset itr back to the beginning for 2nd pass
        
        // 2ns pass - create the next and random links for the cloned list
        while(itr) {
            map[itr]->next = map[itr->next];
            map[itr]->random = map[itr->random];
            itr = itr->next;
        }
        return map[head]; // return head of cloned list, as stored in map
    }
};