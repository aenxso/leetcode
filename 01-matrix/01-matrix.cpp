class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col)
                if (mat[row][col] == 0) q.push({row, col});
                else mat[row][col] = -1; // marked as not processed yet

        vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            vector<int> cur = q.front(); 
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cur[0] + dir[i][0], nc = cur[1] + dir[i][1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[cur[0]][cur[1]] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};
