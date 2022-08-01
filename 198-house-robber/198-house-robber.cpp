class Solution {
public:
    int rob(vector<int>& nums) {
        // dynamic programming - create a vector to store the max amount possible at each step
        // ie. rob current + two houses ago, or skip this house and rob the last house
        
        // base cases
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max((nums[i] + dp[i - 2]), dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};