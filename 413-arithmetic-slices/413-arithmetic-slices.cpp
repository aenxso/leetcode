class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        dfs(nums, n - 1, sum);
        return sum;
    }
    
private:
    int dfs(vector<int>& nums, int i, int& sum) {
        // base case
        if(i < 2) return 0;
        
        int res = 0;
        if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            res = 1 + dfs(nums, i - 1, sum);
            sum += res;
        } else {
            dfs(nums, i - 1, sum);
        }
        return res;
    }
};