class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // adjacency matrix
        // can use either bfs or dfs to solve
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& grid, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j = 0; j < grid.size(); j++) {
            if(i != j && !visited[j] && grid[i][j] == 1) {
                dfs(grid, visited, j);
            }
        }
    }
};