class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // mod k by nums.size() in case k is bigger than amount of elements in nums
        // reverse 0->k, reverse k->end, reverse 0->end
        
        int n = nums.size();
        int mod = k % n;
        
        reverse(nums.begin(), nums.end() - mod);
        reverse(nums.end() - mod, nums.end());
        reverse(nums.begin(), nums.end());
    }
};