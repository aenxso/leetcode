class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // search every index for '1'
        // once found recursively go through islands in cardinal directions and flip 1 to 0 to 'mark' it
        // while flipping keep count of how many indices have been flipped
        
        if(grid.size() == 0) return 0;
        int biggest = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    biggest = max(biggest, dfs(grid, i, j));
                }
            }
        }
        return biggest;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;
        
        return 1 +
               dfs(grid, i + 1, j) +
               dfs(grid, i - 1, j) +
               dfs(grid, i, j + 1) +
               dfs(grid, i, j - 1);
    }
};