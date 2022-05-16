class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0 || grid[m - 1][n - 1] != 0 || grid[0][0] != 0) return -1;
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        
        queue<pair<int, int>> path;
        path.push({0, 0});
        grid[0][0] = 1; // change coordinates of grid as we go along by increasing by 1 -- this changes the values away
                        //  from 0 so no retracing occurs, and gives us the length of the path
        
        while(!path.empty()) {
            auto cur = path.front();
            int x = cur.first, y = cur.second;
            if(x == m - 1 && y == n - 1) return grid[x][y]; // reached the last coordinate, return the last updated value of grid
            
            for(auto dir : dirs) {                          // explore all 8 directions to find 0
                int newX = x + dir[0], newY = y + dir[1];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) { // chack if in bounds
                    path.push({newX, newY});           // add new coordinate to path to explore
                    grid[newX][newY] = grid[x][y] + 1; // update the path length by changing grid value
                }
            }
            path.pop();
        }
        return -1;
    }
};
