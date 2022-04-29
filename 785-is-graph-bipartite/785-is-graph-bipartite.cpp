class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // use BFS
        // store visited nodes in a queue and visited array, pop queue as each node is explored
        // once visited, mark the visited node to avoid cycles
        // time: O(|V| + |E|) - every edge is visited twice, 2|E| just turns into |E|
        
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