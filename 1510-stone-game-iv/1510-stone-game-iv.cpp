class Solution {
public:
    bool winnerSquareGame(int n) {
        // create a bool array and store T/F for all numbers up to n
        // last element in array will be the answer
        // i is simulating representing n
        // dp[i] = true means that for the ith number, alice can win
        // assuming alice loses at n = j, if at some point, alice removes a square number and the remaining
        // number = j, and j is false, then alice can win at point i
        
        vector<bool> dp(n + 1, false);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if(!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};