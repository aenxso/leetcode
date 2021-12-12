class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // fill new array from the end, biggest to smallest
        int low = 0, high = nums.size() - 1;
        vector<int> ans(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(abs(nums[low]) >= abs(nums[high])) {
                ans[i] = nums[low] * nums[low];
                low++;
            } else {
                ans[i] = nums[high] * nums[high];
                high--;
            }
        }
        return ans;
    }
};