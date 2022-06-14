class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // sliding window method
        // create a set to store numbers that have been seen so far
        // as we encounter a repeating number, remove it from the set and increment
        //  the left pointer (make window smaller)
        
        unordered_set<int> seen;
        int maxSum = 0, curSum = 0, l = 0;
        for(int num : nums) {
            while(seen.find(num) != seen.end()) {
                curSum -= nums[l];
                seen.erase(nums[l]);
                l++;
            }
            curSum += num;
            seen.insert(num);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};