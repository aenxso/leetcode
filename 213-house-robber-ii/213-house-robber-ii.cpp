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
        
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> nums1(nums.begin() + 1, nums.end()); // create vector skipping first house
        vector<int> nums2(nums.begin(), nums.end() - 1); // create vector skipping last house
        
        return max(robOriginal(nums1), robOriginal(nums2));
    }
    
private:
    int robOriginal(vector<int>& nums) {
        
        // base cases
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> values(nums.size()); // create vector to store max amount at each house
        values[0] = nums[0];
        values[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            values[i] = max(nums[i] + values[i - 2], values[i - 1]); // either rob current house + everything from second 
                                                                     // last house OR skip the
                                                                     // house if it's not worth
        }
        return values[nums.size() - 1]; // last value stores the max amount of money to rob
    }
};