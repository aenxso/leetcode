class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int result = 0, cur = 0;
        for(int num : nums) {
            int tmp = result;
            result = max(result, cur + num);
            cur = tmp;
        }
        return result;
    }
};
