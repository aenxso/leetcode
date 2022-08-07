class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reverse nums[0] to nums[n-k] of the array, and nums[n-k+1] to nums[n-1], then reverse the whole array again
        // modulo k with nums.size in case k is some huge number and would go out of bounds with the above operation
        
        int n = nums.size();
        int newK = k % n;
        
        reverse(nums.begin(), nums.end() - newK);
        reverse(nums.end() - newK, nums.end());
        reverse(nums.begin(), nums.end());
    }
};