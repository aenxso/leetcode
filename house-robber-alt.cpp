class Solution {
public:
    int rob(vector<int>& nums) {
         // bottom up processing
        
        // base cases
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> values(nums.size()); // create vector to store max amount at each house
        values[0] = nums[0];
        values[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            values[i] = max(nums[i] + values[i - 2], values[i - 1]); // either rob current house + everything from second 
                                                                     // last house OR skip the
                                                                     // house if it's not worth
        }
        return values[nums.size() - 1]; // last value stores the max amount of money to rob
    }
};
