class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // use two pointers - find the beginning and end of the unsorted subarray
        
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
       
        
        // if there are duplicate numbers in the unsorted subarray, we need to include them ie. [1,3,2,2,2]
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int m = i; m <= j; m++) {
            minVal = min(minVal, nums[m]);
            maxVal = max(maxVal, nums[m]);
        }
        
        // extend the temporary window
        while(i > 0 && nums[i - 1] > minVal) i--;
        while(j < n - 1 && nums[j + 1] < maxVal) j++;
        
        ans = j - i + 1;
        return ans;
    }
};