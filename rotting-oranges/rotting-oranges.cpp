class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        
        int minutes = 0, fresh = 0;
        queue<vector<int>> rotten;
        
        // taking stock of board - which coordinates have a rotten orange and how many fresh ones are there
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while(!rotten.empty() && fresh != 0) {
            int n = rotten.size();
            // this loop is one iter of finding a rotten and infecting the adjacent
            for(int i = 0; i < n; i++) {
                vector<int> cur = rotten.front();
                rotten.pop();
                for(int j = 0; j < 4; j++) {
                    int row = cur[0] + dir[j][0];
                    int col = cur[1] + dir[j][1];
                    if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col] != 1) continue; // if out of bounds or not fresh, skip to next iteration
                    grid[row][col] = 2; // make fresh orange rotten
                    rotten.push({row, col}); // add rotten coordinates to rotten q
                    fresh--;
                }
            }
            minutes++;
        }
        cout << "minutes = " << minutes << ", fresh = " <<fresh;
        return fresh == 0 ? minutes : -1;
    }
};