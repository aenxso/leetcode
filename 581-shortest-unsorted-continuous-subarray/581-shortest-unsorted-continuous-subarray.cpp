class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, ans = 0;
        
        for(; i < n - 1; i++) {
            if(nums[i + 1] < nums[i]) {
                break;
            }
        }
        
        for(; j > 0; j--) {
            if(nums[j - 1] > nums[j]) {
                break;
            }
        }
        
        if(i == n - 1) return 0; // array is already sorted
       
        
        // if there are duplicate numbers in the unsorted subarray, we need to include them
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int m = i; m <= j; m++) {
            minVal = min(minVal, nums[m]);
            maxVal = max(maxVal, nums[m]);
        }
        
        while(i > 0 && nums[i - 1] > minVal) i--;
        while(j < n - 1 && nums[j + 1] < maxVal) j++;
        
        ans = j - i + 1;
        return ans;
    }
};