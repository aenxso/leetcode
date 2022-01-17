class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
            - Use modifed binary search even though arr isn't sorted
            - keep going in the direction where nums[x] is bigger - 
                either we find the max element or we reach the end of the array, which ends in a bigger int than nums[end-1]
                since after the end is negative infinity, last element becomes a peak
        */
        
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1]) { // iterate up in increments of one to see every value
                r = mid; // not mid-1 because we know this is the bigger element, so it could be the answer
            } else {
                l = mid + 1; // mid+1 because we know this element is smaller, so we are skipping it
            }
        }
        return l;
    }
};