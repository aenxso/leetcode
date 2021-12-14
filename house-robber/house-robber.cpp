class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int total = 0, prevTotal = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int tmpTotal = total;
            total = max(total, nums[i] + prevTotal); //either don't rob this one (total is bigger), or rob (this house + i-2th) house
            prevTotal = tmpTotal;
        }
        return total;
    }
};