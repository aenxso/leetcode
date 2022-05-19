class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Tarjan's bridge finding algorithm
        
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    vector<int> disc{0}, low{0}; // discovery time, lowest future node
    int time = 1;                // counter to use with disc
    unordered_map<int, vector<int>> edgeMap; // key = specific node, vakue = vector of adjacent nodes
    
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time; // each newly-visited node should set its initial value 
        time++;                        //  for both disc and low to the current value of time before time is incremented
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {     // node is unvisited
                dfs(next, curr);       // recursively call dfs on each of the unvisited adjacent nodes (next) of the current node (curr)
                low[curr] = min(low[curr], low[next]); // update the lowlink value for current node
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) // no looped connection, this edge is a bridge so add to ans
                ans.push_back({curr, next});
        }
    }
    
};