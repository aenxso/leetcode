class Solution {
public:
    int minDistance(string word1, string word2) {
        // create array table to store num of operations needed at string[i] vs. string2[j]
        // dp[i-1][j-1] + 1 (moving diagonally back in table for replacement)
        // dp[i-1][j] + 1 (moving left in table for deletion)
        // dp[i][j-1] + 1 (moving up in table for insertion)
        
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
         // for comparing null strings (string1 len 0 against every index of string2)
         // fill first row and column to cover both strings
        for(int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // if the chars are the same there is no step to be taken, 
                                                  // so the value stays the same as the subsequence before this index
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; // 3-way min compare, add 1 for added step
                }
            }
        }
        return dp[n][m];
    }
};
