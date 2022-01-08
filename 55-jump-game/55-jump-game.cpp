class Solution {
public:
    bool canJump(vector<int>& nums) {
        // iterate through and increase total amount of distance we can cover, ie. max index that can be reached
        // alt solution would be to traverse array backwards
        
        if(nums.size() == 1) return true;
        int target = nums.size() - 1, totalJumpingPower = 0;
        
        for(int i = 0; i <= totalJumpingPower; i++) {
            totalJumpingPower = max(totalJumpingPower, i + nums[i]);
            if(totalJumpingPower >= target) return true;
        }
        return false;
    }
};