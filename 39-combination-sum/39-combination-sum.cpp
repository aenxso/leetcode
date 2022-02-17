class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo; // vector to store possible combinations of numbers
        int sum = 0;
        backtrack(candidates, ans, combo, target, 0, sum);
        
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& combo, int target, int begin, int sum) {
        // subtract current value from target each time so we know how much more we need to add to reach the target
        // when target reaches a perfect 0, we know we have a combination
        // if target becomes less than 0, no solution with current combination - return
        
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(combo);
        }
        
        for(int i = begin; i < nums.size(); i++) {
            combo.push_back(nums[i]);
            backtrack(nums, ans, combo, target, i, sum + nums[i]);
            combo.pop_back();
        }
    }
};