class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, ans = 0;
        
        while(i + 1 < n && nums[i] <= nums[i + 1]) i++;
        while(j - 1 >= 0 && nums[j] >= nums[j - 1]) j--;
        
        if(i == n - 1) return 0; // array is already sorted
        
        // if there are duplicate numbers in the unsorted subarray, we need to include them
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int m = i; m <= j; m++) {
            minVal = min(minVal, nums[m]);
            maxVal = max(maxVal, nums[m]);
        }
        
        while(i - 1 >= 0 && nums[i - 1] > minVal) i--;
        while(j + 1 <= n - 1 && nums[j + 1] < maxVal) j++;
        
        ans = j - i + 1;
        return ans;
    }
};