class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //reverse n-k to n
        //reverse 0 to n-k
        //reverse entire thing
        int len = nums.size();
        int n = k % len; // k may be bigger than nums.size(), but it's still acceptable to rotate x number of times
        reverse(nums.end() - n, nums.end());
        reverse(nums.begin(), nums.end() - n);
        reverse(nums.begin(), nums.end());
    }
};
