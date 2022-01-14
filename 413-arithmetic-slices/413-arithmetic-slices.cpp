class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, totalArrs = 0;
        for(int i = 2; i < nums.size(); i++) { // start at 2 because we need at least elements - anything less than 2 won't work
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                totalArrs += dp; // if the differences are the same we will have dp number additional combos of arith slices
            } else {
                dp = 0; // reset dp if differences are different
            }
        }
        return totalArrs;
    }
};