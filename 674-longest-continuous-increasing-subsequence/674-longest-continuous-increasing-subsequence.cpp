class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, begin = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i - 1] >= nums[i]) {
                begin = i;
            }
            ans = max(ans, i - begin + 1);
        }
        return ans;
    }
};