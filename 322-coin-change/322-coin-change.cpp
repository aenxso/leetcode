class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // create array to store min number of coins needed to make i cents
        // array length = amount + 1, because amount is the end goal. + 1 for accounting for 0
        
        sort(coins.begin(), coins.end()); // optimization - break out of for loop if the coin is too big - leetcode reports as slower tho
        vector<int> dp(amount + 1, (amount + 1)); // fill array with amount + 1 because we need a higher amount to compare 
                                                // with in min function, and the value at dp[i] will not exceed amount
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i) { // if the value of the coin is <= to the amount of cents we're trying to reach (i)
                    dp[i] = min(dp[i], (dp[i - coins[j]] + 1)); // min of current value we have at ddp[i] or taking current
                                                              // coin (this is the + 1) and a value previously computed for 
                                                              // remaining value needed to reach amount
                } else {
                    break;
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // if dp[amount] hasn't changhed from what we initally set it to, ie (amount+1)
                                                      // then we know we never reached a solution for it
    }
};