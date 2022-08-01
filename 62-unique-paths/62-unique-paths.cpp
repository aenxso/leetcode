class Solution {
public:
    int uniquePaths(int m, int n) {
        // create array to keep track of numbers of way to reach every cell
        // update each array by adding the vals from cell to the left, and from above
        // ^ since we know we can only move right or down (given restriction)
        // DP - subproblem essentially becomes, how many ways can we reach each cell
        
        vector<vector<int>> numWays(m, vector<int>(n, 1)); // create 2d array starting off with values of 1
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                numWays[i][j] = numWays[i - 1][j] + numWays[i][j - 1]; // current value = previous row val + previous col val
            }
        }
        return numWays[m - 1][n - 1];
    }
};