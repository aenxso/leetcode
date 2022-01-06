class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // find all the O's on the border and change them to something else
        // find all the O's on the inside and change them to another something else
        // go through the board in nested loop and change each char to what it should be (border O's back to O, and inside O's to X)
        if(board.size() == 0) return;
        queue<pair<int, int>> q;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        // traverse borders and mark O's as 'B'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = 'B';
                }
            }
        }
        
        // bfs
        while(!q.empty()) {
            auto cur = q.front();
            int x = cur.first, y = cur.second;
            q.pop();
            for(auto dir : dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'O') {
                    q.push({newX, newY});
                    board[newX][newY] = 'B';
                }
            }
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};


