class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // use DFS and memoization and recursion
        
        int n = matrix.size(), m = matrix[0].size(), longest = 0;
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> cache(n, vector<int>(m)); // memoization - stores length of longest path starting at each coordinate
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int curPath = dfs(matrix, cache, n, m, i, j);
                longest = max(longest, curPath);
            }
        }
        return longest;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int n, int m, int i, int j) {
        if(cache[i][j] > 0) return cache[i][j]; // coordinate has already been explored
        
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int maxPath = 0;
        
        for(auto dir : dirs) {
            int x = dir[0] + i, y = dir[1] + j;
            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) { // in bounds and strictly increasing
                int curPath = dfs(matrix, cache, n, m, x, y);
                maxPath = max(maxPath, curPath); // out of all 4 directions, get the max stored path length (comes from cache vector)
            }
        }
        cache[i][j] = maxPath + 1; // add one because it is a path itself at every coordinate
        return cache[i][j];        // return the length of longest path at that coordinate
    }
};