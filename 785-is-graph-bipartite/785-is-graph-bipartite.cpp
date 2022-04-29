class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> visited(n);
        
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue; // if already visited, skip
            
            visited[i] = 1;
            for(q.push(i); !q.empty(); q.pop()) { // @zzg_zzm for this line
                int cur = q.front();
                for(int neighbour : graph[cur]) {
                    if(!visited[neighbour]) {
                        visited[neighbour] = -visited[cur]; // change value to mark the node
                        q.push(neighbour);                  // add it to the queue to visit its nodes later
                    } else if(visited[neighbour] == visited[cur]) { // if 2 nodes beside each other are the same 'colour'
                        return false; 
                    }
                }
            }
        }
        return true;
    }
};