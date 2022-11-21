class Solution {
public:
    int dirx[4] = { -1, 0, 0, 1 };
    int diry[4] = { 0, 1, -1, 0 };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<array<int, 3>> q; // {i, j, steps}
        // push the starting point (i, j) with initial step 0
        q.push({entrance[0], entrance[1], 0});
        // BFS
        while (!q.empty()) {
            auto [i, j, steps] = q.front(); q.pop();
            // handle exit condition, we can exit if
            // 1. the current position is not the entrance 
            bool isAtTheEntrance = i == entrance[0] && j == entrance[1];
            // 2. and the current position is at the border
            bool isAtTheBorder = i == 0 || j == 0 || i == m - 1 || j == n - 1;
            if(!isAtTheEntrance && isAtTheBorder) return steps;
            // try for 4 directions
            for(int d = 0; d < 4; d++) {
                int nextI = i + dirx[d];
                int nextJ = j + diry[d];
                // check if we can move to (next_i, next_j)
                if(nextI >= 0 && nextJ >= 0 && nextI < m && nextJ < n && maze[nextI][nextJ] == '.') {
                    // if so, we mark the next cell to `+` so that we won't visit it again
                    maze[nextI][nextJ] = '+';
                    // add the next position to the queue with steps + 1
                    q.push({nextI, nextJ, steps + 1});
                }
            }
        }
        return -1;
    }
};