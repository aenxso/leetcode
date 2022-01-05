class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;
        
        queue<pair<int, int>> path;
        path.push({0, 0});
        grid[0][0] = 1;
        vector<vector<int>> dir = {{1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}};
        
        while(!path.empty()) {
            auto cur = path.front();
            int x = cur.first, y = cur.second;
            if(x == m - 1 && y == n - 1) return grid[x][y]; // if coords match last that of cell we know we've reach the end
                                                            // return last updated value at coordinate, since we've been increasing by 1 each step
            for(auto dirs : dir) {
                int newX = x + dirs[0], newY = y + dirs[1];
                if(newX >=  0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) { // check if in bounds
                    path.push({newX, newY}); // update q with new coord we have moved to
                    grid[newX][newY] = grid[x][y] + 1; // increase val at each new index by 1 to keep track of how many cells we've visited
                                                       // this changes the value from 0 as well so we don't retrace steps
                }
            }
            
            path.pop(); // pop off old coordinates
        }
        return -1;
    }
};