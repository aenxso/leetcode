class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        
        int ans = 0, cur = 1, left = 0, right = 0;
        
        while(right < nums.size()) {
            cur *= nums[right];
            while(cur >= k && left <= right) { // since the product has become too big, keep dividing by the left element and increment left pointer
                cur /= nums[left];
                left++;
            }
            ans += 1 + (right - left); // number of arrs is equal to the num itself (hence +1) and the number of elements we added in the while loop (hence r - l)
            right++;
        }
        return ans;
    }
};