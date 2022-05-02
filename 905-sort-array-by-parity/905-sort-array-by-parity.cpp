class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans, even, odd;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        
        for(int i : even) {
            ans.push_back(i);
        }
        
        for(int i : odd) {
            ans.push_back(i);
        }
        
        return ans;
    }
};