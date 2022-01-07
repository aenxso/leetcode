class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        vector<int> comb;
        
        backtrack(nums, ans, comb, target, 0);
        
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& comb, int target, int begin) {
        // subtract current value from target each time so we know how much more we need to add to reach the target
        // when target reaches a perfect 0, we know we have a combination
        // if target becomes less than 0, no solution with current combination
        
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(comb);
        }
        
        for(int i = begin; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            backtrack(nums, ans, comb, target - nums[i], i);
            comb.pop_back();
        }
    }
};