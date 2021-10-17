class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1; // create two 'pointers'
        for(int i = nums.size() - 1; i >= 0; i--) { // fill answer arr starting from the back - biggest to smallest
           if(abs(nums[l]) > abs(nums[r])) {
               ans[i] = nums[l] * nums[l];
               l++;
           } else {
               ans[i] = nums[r] * nums[r];
               r--;
           }
        }
        return ans;
    }
};
