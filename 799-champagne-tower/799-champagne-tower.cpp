class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // use dp 2d array which is 101 x 101 (as constraints say 0 <= query_glass <= query_row < 100)
        // the beginning value of the dp array is poured, and from there the amount will become smaller
        //   with every iteration down the champagne tower
        
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = poured; // setting the top glass with the value of how many 'pours' are left
        
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] > 1) {  // if the glass is full and has more pours left then set values for the next glasses
                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1; // set value of glass to 1 as its pours have been moved onto the next row
                }
            }
        }
        return dp[query_row][query_glass];
    }
};