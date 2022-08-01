class Solution {
public:
    int rob(vector<int>& nums) {
        /* same as house robber but now add a check for the first "base case", which is nums[0] vs. nums[n - 1]
           values[0] = max(nums[n - 1], nums[0]); values[1] = max(values[0], nums[1]); doesn't work because nums[n]
           needs to contain all the values up to that point - not just nums[n].
           Therefore, using a vector to store the vals at each house we run into the problem of needing to skip the first or last house 
           altogether but obviously this isn't a viable solution. So instead run the function twice - once skipping the first house,
           one skipping the last house. Return the max between these two functions.
        */
        
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> nums1(nums.begin(), nums.end() - 1); // vector skipping last house
        vector<int> nums2(nums.begin() + 1, nums.end()); // vector skipping first house
        
        return max(robberOriginal(nums1), robberOriginal(nums2));
    }
    
private:
     int robberOriginal(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size()) ;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max((nums[i] + dp[i - 2]), dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};