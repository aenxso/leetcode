class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0 || grid[m - 1][n - 1] != 0 || grid[0][0] != 0) return -1;
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        
        queue<pair<int, int>> path;
        path.push({0, 0});
        grid[0][0] = 1;
        
        while(!path.empty()) {
            auto cur = path.front();
            int x = cur.first, y = cur.second;
            if(x == m - 1 && y == n - 1) return grid[x][y]; // reached the last coordinate
            
            for(auto dir : dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    path.push({newX, newY});
                    grid[newX][newY] = grid[x][y] + 1;
                }
            }
            path.pop();
        }
        return -1;
    }
};
