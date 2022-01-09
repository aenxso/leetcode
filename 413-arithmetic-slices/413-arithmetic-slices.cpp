class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, totalSum = 0;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                totalSum += dp;
            } else {
                dp = 0;
            }
        }
        return totalSum;
    }

};