class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // solution using an int value to keep track of whether or not there was a slice
        // since we are looking at 3-element windows, we have to keep moving up our window and
        //   using a dp int keeps track of whether the elements before were also a sequence
        //   as we can keep adding onto it. This ensures we can check every slice without
        //   worrying about restting the start and end points when a sequence ends.
        // reset dp to 0 when the sequence breaks 
        // time: O(n), space: O(1)
        
        if(nums.size() < 3) return 0;
        int ans = 0, dp = 0;
        
        // start at because anything less than 2 won't work, and we need to go back that many spaces
        for(int i = 2; i < nums.size(); i++) { 
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                ans += dp;
            } else {
                dp = 0; // reset dp to 0 if the sequence is disrupted
            }
        }
        return ans;
    }
};