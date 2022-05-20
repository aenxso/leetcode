class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0; // no solution
        int ans = 0, n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> cache(n + 1, vector<long long>(m + 1, 0)); // memoization
        cache[0][1] = 1; // ensure robot has a way out - preprocessing
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!obstacleGrid[i - 1][j -1 ]) {
                    cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
                }
            }
        }
        return cache[n][m];
    }

};