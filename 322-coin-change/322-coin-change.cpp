class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dynamic programming - find the min number of coins needed to make i cents
        
        sort(coins.begin(), coins.end());
        vector<int> dp (amount + 1, (amount + 1)); // size is amount+1 to account for 0 cents, filling dp with amount+1
                                                   // because we need a higher amount to compare to when we reach the min() function
        dp[0] = 0; // 0 cents
        
        for(int i = 1; i <= amount; i++) {          // first loop is to match i cents, up to the amount
            for(int j = 0; j < coins.size(); j++) { // second loop is to go through the coins available
                if(coins[j] <= i) {                 // if coins[j] is <= the amount we're currently trying to reach, which is the value of i
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); // min of current value we have at ddp[i] or taking current
                                                              // coin (this is the + 1) and a value previously computed for 
                                                              // remaining value needed to reach amount
                } else {
                    break;
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // if dp[amount] is still great than amount (because it was set to amount+1)
                                                      // then we know we never reached a solution
    }
};