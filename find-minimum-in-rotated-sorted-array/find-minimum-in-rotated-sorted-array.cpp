class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) { // if nums[mid] is higher than the 'high' value
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};