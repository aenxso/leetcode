class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target) {
            return 0;
        } else if(nums.size() == 1 && nums[0] != target) {
            return -1;
        }
        
        // find the index of the lowest number
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > nums[high]) { 
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        // after finding the real start, determine whether it is to right or left of target and assign low/high accordingly
        int newLow = low;
        low = 0, high = nums.size() - 1;
        if(nums[newLow] <= target && nums[high] >= target) {
            low = newLow;
        } else {
            high = newLow;
        }
        
        // perform regular binary search with new index values for low/high
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};