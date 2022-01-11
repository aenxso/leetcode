class Solution {
public:
    int minDistance(string word1, string word2) {
        // find the longest common subsequence, then delete unnecessary number of chars
        
        int n = word1.size(), m = word2.size(), longest = 0, steps = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        longest = dp[n][m];
        steps = (n - longest) + (m - longest); // remove longest subsequence length from both, then add to get combined num of steps needed
        return steps;
    }
};