class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort the array in order to find the true median value
        // # of steps required will be the difference between every element
        //  and the found median
        
        sort(nums.begin(), nums.end());
        int steps = 0;
        int median = nums[nums.size() / 2];
        for(int i = 0; i < nums.size(); i++) {
            steps += abs(median - nums[i]);
        }
        return steps;
    }
};