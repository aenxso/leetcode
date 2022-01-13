class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), longest = 1, ansStart = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // length 1 substr
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // length 2 substr
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ansStart = i;
                longest = 2;
            }
        }
        
        // length 3+ substr
        for(int k = 3; k <= n; k++) { // k represents length of string, thus it starts at 3
            for(int i = 0; i < n - k + 1; i++) {
                int j = k + i - 1; // ending index
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if(k > longest) {
                        ansStart = i;
                        longest = k;
                    }
                }
            }
        }
        return s.substr(ansStart, longest);
    }
};